#include <include/kitchen.h>
#include <iostream>
#include <chrono>
#include <cstdlib>

Kitchen::Kitchen()
    : cookingInProgress_(false)
    , stopRequested_(false)
{
    std::srand(std::time(nullptr));
}

Kitchen::~Kitchen()
{
    Stop();
}

void Kitchen::AddOrder(DishType dish)
{
    {
        std::lock_guard<std::mutex> lock(mtx_);
        incomingOrders_.push(dish);
    }
    cvIncoming_.notify_all();
}

bool Kitchen::TakeReadyOrder(DishType& dish)
{
    std::lock_guard<std::mutex> lock(mtx_);
    if (readyOrders_.empty())
    {
        return false;
    }
    dish = readyOrders_.front();
    readyOrders_.pop();
    return true;
}

bool Kitchen::HasReadyOrders() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    return !readyOrders_.empty();
}

void Kitchen::Start()
{
    cookingThread_ = std::thread(&Kitchen::CookingLoop, this);
}

void Kitchen::Stop()
{
    if (cookingThread_.joinable())
    {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            stopRequested_ = true;
        }
        cvIncoming_.notify_all();
        cookingThread_.join();
    }
}

void Kitchen::CookingLoop()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx_);
        cvIncoming_.wait(lock, [this]
        {
            return !incomingOrders_.empty() || stopRequested_;
        });

        if (stopRequested_)
        {
            break;
        }

        DishType dish = incomingOrders_.front();
        incomingOrders_.pop();
        cookingInProgress_ = true;
        lock.unlock();

        std::cout << "Kitchen started cooking " << DishTypeToString(dish) << std::endl;

        int cookingTime = 5 + std::rand() % 11;
        std::this_thread::sleep_for(std::chrono::seconds(cookingTime));

        {
            std::lock_guard<std::mutex> lock(mtx_);
            readyOrders_.push(dish);
            cookingInProgress_ = false;
        }
        std::cout << "Kitchen finished cooking " << DishTypeToString(dish) << std::endl;
        cvReady_.notify_all();
    }
}

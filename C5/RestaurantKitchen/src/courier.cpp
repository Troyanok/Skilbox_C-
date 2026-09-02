#include <include/courier.h>
#include <iostream>
#include <chrono>

Courier::Courier(Kitchen& kitchen, int maxDeliveries)
    : kitchen_(kitchen)
    , maxDeliveries_(maxDeliveries)
{}

void Courier::Start()
{
    thread_ = std::thread(&Courier::Run, this);
}

void Courier::Join()
{
    if (thread_.joinable())
    {
        thread_.join();
    }
}

bool Courier::IsFinished() const
{
    return finished_.load();
}

int Courier::GetDeliveredCount() const
{
    return deliveredCount_.load();
}

void Courier::Run()
{
    while (deliveredCount_ < maxDeliveries_)
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "Courier arrived for pickup." << std::endl;

        while (kitchen_.HasReadyOrders())
        {
            DishType dish;
            if (kitchen_.TakeReadyOrder(dish))
            {
                deliveredCount_++;
                std::cout << "Courier delivered " << DishTypeToString(dish)
                          << ". Total deliveries: " << deliveredCount_ << std::endl;
                if (deliveredCount_ >= maxDeliveries_)
                {
                    break;
                }
            }
        }
        if (deliveredCount_ >= maxDeliveries_)
        {
            finished_ = true;
            break;
        }
    }
}

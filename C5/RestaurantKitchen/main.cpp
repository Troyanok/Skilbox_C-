#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <include/kitchen.h>
#include <include/courier.h>

int main()
{
    std::srand(std::time(nullptr));

    Kitchen kitchen;
    Courier courier(kitchen, 10); // 10 успешных доставок

    kitchen.Start();
    courier.Start();

    int orderCounter = 0;
    while (!courier.IsFinished())
    {
        int waitTime = 5 + std::rand() % 6; // 5..10
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));

        DishType dish = static_cast<DishType>(std::rand() % 5);
        std::cout << "New order received: " << DishTypeToString(dish) << std::endl;
        kitchen.AddOrder(dish);
    }

    courier.Join();
    kitchen.Stop();

    std::cout << "Program finished. Total deliveries: " << courier.GetDeliveredCount() << std::endl;
    return 0;
}

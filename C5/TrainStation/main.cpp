#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <include/train.h>
#include <include/station.h>

int main()
{
    Station station;
    std::vector<std::unique_ptr<Train>> trains;
    const int trainCount = 3;
    std::vector<std::string> names = {"A", "B", "C"};

    std::cout << "Enter travel times (in seconds) for trains A, B, C:" << std::endl;
    for (int i = 0; i < trainCount; ++i)
    {
        int time;
        std::cout << "Train " << names[i] << ": ";
        std::cin >> time;
        trains.push_back(std::make_unique<Train>(names[i], time, &station));
    }

    for (auto& t : trains)
    {
        t->Start();
    }

    std::string command;
    int visitedCount = 0;
    while (visitedCount < trainCount)
    {
        std::cout << "> ";
        std::cin >> command;
        if (command == "depart")
        {
            if (station.IsOccupied())
            {
                std::string current = station.GetCurrentTrain();
                std::cout << "Train " << current << " is departing." << std::endl;
                station.Depart(current);
                visitedCount++;
            }
            else
            {
                std::cout << "No train at station." << std::endl;
            }
        }
        else
        {
            std::cout << "Unknown command. Use 'depart'." << std::endl;
        }
    }

    for (auto& t : trains)
    {
        t->Join();
    }

    std::cout << "All trains have visited the station. Program finished." << std::endl;
    return 0;
}

#include <iostream>
#include "include/average.h"

int main() {
    std::cout << "Choose array type:" << std::endl;
    std::cout << "1) int\n2) double\n3) float" << std::endl";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int arr[8];
            InputArray(arr);
            std::cout << "Average: " << Average(arr) << std::endl;
            break;
        }
        case 2:
        {
            double arr[8];
            InputArray(arr);
            std::cout << "Average: " << Average(arr) << std::endl;
            break;
        }
        case 3:
        {
            float arr[8];
            InputArray(arr);
            std::cout << "Average: " << Average(arr) << std::endl;
            break;
        }
        default:
        {
            std::cerr << "Invalid choice" << std::endl;
            return 1;
        }
    }
    return 0;
}

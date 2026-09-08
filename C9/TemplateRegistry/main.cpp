#include <iostream>
#include <string>
#include "include/registry.h"

/// @brief Шаблонная функция ввода данных в реестр
template <typename KeyType, typename ValueType>
void AddToRegistry(Registry<KeyType, ValueType>& reg,
                   const std::string& keyPrompt,
                   const std::string& valuePrompt)
{
    KeyType key;
    ValueType value;
    std::cout << keyPrompt;
    std::cin >> key;
    std::cout << valuePrompt;
    std::cin >> value;
    reg.Add(key, value);
}

/// @brief Шаблонная функция удаления по ключу
template <typename KeyType, typename ValueType>
void RemoveFromRegistry(Registry<KeyType, ValueType>& reg,
                        const std::string& keyPrompt)
{
    KeyType key;
    std::cout << keyPrompt;
    std::cin >> key;
    reg.Remove(key);
}

/// @brief Шаблонная функция поиска по ключу
template <typename KeyType, typename ValueType>
void FindInRegistry(const Registry<KeyType, ValueType>& reg,
                    const std::string& keyPrompt)
{
    KeyType key;
    std::cout << keyPrompt;
    std::cin >> key;
    reg.Find(key);
}

int main()
{
    std::cout << "Choose types for registry:" << std::endl;
    std::cout << "1) int key, int value" << std::endl;
    std::cout << "2) double key, double value" << std::endl;
    std::cout << "3) string key, string value" << std::endl;
    int choice;
    std::cin >> choice;
    std::string command;

    if (choice == 1)
    {
        Registry<int, int> reg;
        std::cout << "Commands: add, remove, print, find, exit\n";
        while (true)
        {
            std::cout << "> ";
            std::cin >> command;
            if (command == "add")
            {
                AddToRegistry(reg, "Key: ", "Value: ");
            }
            else if (command == "remove")
            {
                RemoveFromRegistry(reg, "Key: ");
            }
            else if (command == "print")
            {
                reg.Print();
            }
            else if (command == "find")
            {
                FindInRegistry(reg, "Key: ");
            }
            else if (command == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command\n";
            }
        }
    }
    else if (choice == 2)
    {
        Registry<double, double> reg;
        std::cout << "Commands: add, remove, print, find, exit" << std::endl;
        while (true)
        {
            std::cout << "> ";
            std::cin >> command;
            if (command == "add")
            {
                AddToRegistry(reg, "Key: ", "Value: ");
            }
            else if (command == "remove")
            {
                RemoveFromRegistry(reg, "Key: ");
            }
            else if (command == "print")
            {
                reg.Print();
            }
            else if (command == "find")
            {
                FindInRegistry(reg, "Key: ");
            }
            else if (command == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command" << std::endl;;
            }
        }
    }
    else if (choice == 3)
    {
        Registry<std::string, std::string> reg;
        std::cout << "Commands: add, remove, print, find, exit" << std::endl;
        while (true)
        {
            std::cout << "> ";
            std::cin >> command;
            if (command == "add")
            {
                AddToRegistry(reg, "Key: ", "Value: ");
            }
            else if (command == "remove")
            {
                RemoveFromRegistry(reg, "Key: ");
            }
            else if (command == "print")
            {
                reg.Print();
            }
            else if (command == "find")
            {
                FindInRegistry(reg, "Key: ");
            }
            else if (command == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Invalid choice" << std::endl;
    }
    return 0;
}

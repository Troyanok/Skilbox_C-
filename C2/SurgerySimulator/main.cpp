#include <iostream>
#include <include/surgery_tools.h>

int main()
{
    std::string command;
    surgery_tools::Point start, end, p;
    bool operationStarted { false };
    surgery_tools::Point scalpelStart, scalpelEnd;

    std::cout << "Добро пожаловать в симулятор операции" << std::endl;

    while (1)
    {
        std::cout << "Введите команду для текущего шага операции: " << std::endl;
        std::cout << "\t scalpel - Провести разрез между 2мя координатами;" << std::endl;
        std::cout << "\t hemostat - Установить зажим в конкретной координате;" << std::endl;
        std::cout << "\t tweezers - Установить пинцет в конкретной координате;" << std::endl;
        std::cout << "\t suture - Сделать шов между 2мя координатами;" << std::endl;
        std::cout << "\t exit - Завершить работу программы." << std::endl;
        std::cin >> command;

        if (command == "exit")
        {
            std::cout << "Завершение программы" << std::endl;
            break;
        }

        if (command == "scalpel")
        {
            std::cout << "Введите координаты начала разреза: " << std::endl;
            surgery_tools::InputPoint(start);
            std::cout << "Введите координаты конца разреза: " << std::endl;
            surgery_tools::InputPoint(end);
            surgery_tools::ScalpelAction(start, end);
            if (!operationStarted)
            {
                scalpelStart = start;
                scalpelEnd = end;
                operationStarted = true;
                std::cout << "Операция началась. Для завершения используйте suture с теми же координатами" << std::endl;
            }
        }
        else if (command == "hemostat")
        {
            if (!operationStarted)
            {
                std::cout << "Сначала необходимо выполнить разрез (scalpel)" << std::endl;
                continue;
            }
            std::cout << "Введите точку для зажима: " << std::endl;
            surgery_tools::InputPoint(p);
            surgery_tools::HemostatAction(p);
        }
        else if (command == "tweezers")
        {
            if (!operationStarted) 
            {
                std::cout << "Сначала необходимо выполнить разрез (scalpel)" << std::endl;
                continue;
            }
            std::cout << "Введите точку для пинцета: " << std::endl;
            surgery_tools::InputPoint(p);
            surgery_tools::TweezersAction(p);
        }
        else if (command == "suture")
        {
            if (!operationStarted)
            {
                std::cout << "Сначала необходимо выполнить разрез (scalpel)" << std::endl;
                continue;
            }
            std::cout << "Введите координаты начала шва: " << std::endl;
            surgery_tools::InputPoint(start);
            std::cout << "Введите координаты конца шва: " << std::endl;
            surgery_tools::InputPoint(end);
            surgery_tools::SutureAction(start, end);

            if (surgery_tools::CheckEqualPoints(start, scalpelStart) && surgery_tools::CheckEqualPoints(end, scalpelEnd))
            {
                std::cout << "Операция успешно завершена! Шов совпадает с первоначальным разрезом" << std::endl;
                break;
            }
            else
            {
                std::cout << "Шов наложен, но он не совпадает с разрезом. Операция продолжается" << std::endl;
            }
        }
        else
        {
            std::cout << "Неизвестная команда. Повторите ввод" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

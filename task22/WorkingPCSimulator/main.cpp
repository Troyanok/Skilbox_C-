#include <include/cpu.h>
#include <include/disk.h>
#include <include/gpu.h>
#include <include/kbd.h>
#include <include/ram.h>

#include <iostream>

int main()
{
    std::string command;

    std::cout << "Добро пожаловать в симулятор работы компьютера" << std::endl;

    while (1)
    {
        std::cout << "Введите команду для текущего шага : " << std::endl;
        std::cout << "\t sum - Вычислить сумму в буфере оперативной памяти;" << std::endl;
        std::cout << "\t save - Сохранить буфер оперативной памяти в файл data.txt;" << std::endl;
        std::cout << "\t load - Прочитать буфер оперативной памяти из файла data.txt;" << std::endl;
        std::cout << "\t input - Ввести вручную данные в буфер оперативной памяти;" << std::endl;
        std::cout << "\t display - Вывести содержимое оперативной памяти;" << std::endl;
        std::cout << "\t exit - Завершить работу программы." << std::endl;
        std::cin >> command;

        if (command == "exit")
        {
            std::cout << "Завершение программы" << std::endl;
            break;
        }

        if (command == "sum")
        {
            cpu_tools::CalculateRamBuffSum();
        }
        else if (command == "save")
        {
            disk_tools::SaveRamMemoryToFile();
        }
        else if (command == "load")
        {
            disk_tools::LoadRamMemoryFromFile();
        }
        else if (command == "input")
        {
            kbd_tools::InputRamValue();
        }
        else if (command == "display")
        {
            gpu_tools::PrintRamValue();
        }
        else
        {
            std::cout << "Неизвестная команда. Повторите ввод" << std::endl;
        }

        std::cout << std::endl;
    }
    return 0;
}

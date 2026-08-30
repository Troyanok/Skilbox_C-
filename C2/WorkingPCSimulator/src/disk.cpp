#include <include/ram.h>
#include <include/constants.h>

#include <fstream>
#include <iostream>

namespace disk_tools
{
    
void SaveRamMemoryToFile() noexcept
{
    std::ofstream fout("data.txt");
    if (!fout)
    {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }
    for (int i = value_constants::MIN_RAM_VALUE; i < value_constants::MAX_RAM_VALUE; ++i)
    {
        fout << ram_tools::ReadBuffer(i);
        if (i < value_constants::MAX_RAM_VALUE - 1)
        {
            fout << " ";
        }
    }
    fout.close();
    std::cout << "Состояние памяти сохранено в data.txt" << std::endl;
}

void LoadRamMemoryFromFile() noexcept
{
    std::ifstream fin("data.txt");
    if (!fin)
    {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return;
    }
    for (int i = value_constants::MIN_RAM_VALUE; i < value_constants::MAX_RAM_VALUE; ++i)
    {
        int val;
        if (fin >> val)
        {
            ram_tools::WriteBuffer(i, val);
        }
        else
        {
            std::cerr << "Ошибка чтения из файла." << std::endl;
            break;
        }
    }
    fin.close();
    std::cout << "Данные загружены из data.txt в память." << std::endl;
}

}

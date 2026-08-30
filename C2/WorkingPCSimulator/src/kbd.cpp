#include <include/constants.h>
#include <include/ram.h>

#include <iostream>

namespace kbd_tools
{
    
void InputRamValue() noexcept
{
    std::cout << "Заполнение буфера памяти с клавиатуры: " << std::endl;

    for (int i = value_constants::MIN_RAM_VALUE; i < value_constants::MAX_RAM_VALUE; ++i)
    {
        int value;
        std::cout << "Число " << (i + 1) << ": ";
        std::cin >> value;
        ram_tools::WriteBuffer(i, value);
    }
    std::cout << "Данные записаны в память." << std::endl;
}

}

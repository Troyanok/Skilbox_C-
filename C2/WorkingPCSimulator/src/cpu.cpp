#include <include/constants.h>
#include <include/ram.h>
#include <iostream>

namespace cpu_tools
{

void CalculateRamBuffSum() noexcept
{
    int sumRes { 0 };
    for (int i = value_constants::MIN_RAM_VALUE; i < value_constants::MAX_RAM_VALUE; i++)
    {
        sumRes += ram_tools::ReadBuffer(i);
    }
    std::cout << "Сумма значений из буфера оперативной памяти: " << sumRes << std::endl;
}

}

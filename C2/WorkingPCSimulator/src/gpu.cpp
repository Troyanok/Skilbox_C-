#include <include/constants.h>
#include <include/gpu.h>
#include <include/ram.h>

#include <iostream>

namespace gpu_tools
{
    
void PrintRamValue() noexcept
{
    std::cout << "Содержимое памяти (8 чисел): ";
    for (int i = value_constants::MIN_RAM_VALUE; i < value_constants::MAX_RAM_VALUE; i++)
    {
        std::cout << ram_tools::ReadBuffer(i) << " ";
    }
    std::cout << std::endl;
}

}

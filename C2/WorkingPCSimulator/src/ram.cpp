#include <include/constants.h>
#include <include/ram.h>

namespace ram_tools
{
namespace
{

/// @brief Буфер оперативной памяти
int ram_memory[value_constants::MAX_RAM_VALUE] = {};

}

void WriteBuffer(int index, int value) noexcept
{
    if ((index >= value_constants::MIN_RAM_VALUE) && (index < value_constants::MAX_RAM_VALUE))
    {
        ram_memory[index] = value;
    }
}

int ReadBuffer(int index) noexcept
{
    if ((index >= value_constants::MIN_RAM_VALUE) && (index < value_constants::MAX_RAM_VALUE))
    {
        return ram_memory[index];
    }
    return 0;
}

}

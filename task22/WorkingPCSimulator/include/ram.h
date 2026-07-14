#pragma once

namespace ram_tools
{

/// @brief Записать значение в буфер оперативной памяти
/// @param[in] index Индекс, по которому надо записать значение в буфер оперативной памяти
/// @param[in] value Значение, которое надо записать в буфер оперативной памяти
void WriteBuffer(int index, int value) noexcept; 

/// @brief Получить значение из буфера оперативной памяти по конкретному индексу
/// @param[in] index Индекс буфера оперативной памяти
/// @return Значение из буфера оперативной памяти
int ReadBuffer(int index) noexcept;

}

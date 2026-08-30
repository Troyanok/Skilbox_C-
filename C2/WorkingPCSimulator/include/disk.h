#pragma once

namespace disk_tools
{

/// @brief Сохранить буфер оперативной памяти в файл
void SaveRamMemoryToFile() noexcept;

/// @brief Прочитать буфер оперативной памяти из файла
void LoadRamMemoryFromFile() noexcept;

}

#pragma once

#include <string>

/// @brief Перечисление типов блюд.
enum class DishType
{
    Pizza,
    Soup,
    Steak,
    Salad,
    Sushi
};

/// @brief Преобразует тип блюда в строку.
/// @param type Тип блюда.
/// @return Строка с названием.
std::string DishTypeToString(DishType type);

#pragma once
#include <iostream>

/// @brief Шаблонная функция для ввода массива
/// @tparam T Тип элементов
/// @param array Массив (размер 8)
template <typename T>
void InputArray(T array[8])
{
    std::cout << "Fill the array (8 elements):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

/// @brief Шаблонная функция подсчёта среднего арифметического
/// @tparam T Тип элементов (скалярный арифметический)
/// @param array Массив (размер 8)
/// @return Среднее арифметическое (double)
template <typename T>
double Average(const T array[8])
{
    double sum = 0.0;
    for (int i = 0; i < 8; ++i)
    {
        sum += static_cast<double>(array[i]);
    }
    return sum / 8.0;
}

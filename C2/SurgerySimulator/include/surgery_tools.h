#include <iostream>

#pragma once

namespace surgery_tools
{

/// @brief Структура точки с координатами x и y
struct Point
{
    double x; ///< Координата по оси OX
    double y; ///< Координата по оси OY

    /// @brief Конструктор по умолчанию
    Point();
};

/// @brief Получить координаты текущей точки
/// @param[out] curPoint Полученная точка
void InputPoint(Point& curPoint);

/// @brief Проверить, совпадают ли точки покоординатно
/// @param[in] first Первая точка
/// @param[in] second Вторая точка
/// @return true Точки совпали, иначе - false
bool CheckEqualPoints(const Point& first, const Point& second);

/// @brief Провести надрез между двумя точками
/// @param[in] first Первая точка
/// @param[in] second Вторая точка
void ScalpelAction(const Point& first, const Point& second);

/// @brief Установить зажиима в указанной точке
/// @param[in] currentPoint Точка для установа зажима
void HemostatAction(const Point& currentPoint);

/// @brief Установить пинцет в указанной точке
/// @param[in] currentPoint Точка для установа пинцета
void TweezersAction(const Point& currentPoint);

/// @brief Наложить шов между указанными точками
/// @param[in] first Первая точка
/// @param[in] second Вторая точка
void SutureAction(const Point& first, const Point& second);

/// @brief Напечатать координаты текущей точки
/// @param[in] currentPoint Точка, для которой надо вывести содержимое
void PrintPoint(const Point& currentPoint);

}

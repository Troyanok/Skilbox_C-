#pragma once

#include <include/figure.h>

/// @brief Класс, представляющий равносторонний треугольник
/// Наследуется от Figure, добавляет длину стороны
class EquilateralTriangle : public Figure
{
public:
    /// @brief Конструктор равностороннего треугольника
    /// @param centerX Координата X центра
    /// @param centerY Координата Y центра
    /// @param side Длина стороны (должна быть положительной)
    /// @param color Цвет треугольника
    /// @throw std::invalid_argument если side <= 0
    EquilateralTriangle(double centerX, double centerY, double side, Color color);

    /// @brief Вычисляет площадь равностороннего треугольника
    /// @return Площадь (a² * √3 / 4)
    double GetArea() const override;

    /// @brief Возвращает описывающий прямоугольник
    /// @return BoundingBox: ширина = a, высота = a * √3 / 2
    BoundingBox GetDescribingRectangle() const override;

    /// @brief Возвращает длину стороны
    /// @return Длина стороны
    double GetSide() const
    {
        return side_;
    }

private:
    double side_; ///< Длина стороны треугольника
};
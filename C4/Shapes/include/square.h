#pragma once

#include <include/figure.h>

/// @brief Класс, представляющий квадрат
/// Наследуется от Figure, добавляет длину стороны
class Square : public Figure
{
public:
    /// @brief Конструктор квадрата
    /// @param centerX Координата X центра
    /// @param centerY Координата Y центра
    /// @param side Длина стороны (должна быть положительной)
    /// @param color Цвет квадрата
    /// @throw std::invalid_argument если side <= 0
    Square(double centerX, double centerY, double side, Color color);

    /// @brief Вычисляет площадь квадрата
    /// @return Площадь (a²)
    double GetArea() const override;

    /// @brief Возвращает описывающий прямоугольник (совпадает с квадратом)
    /// @return BoundingBox с размерами side x side
    BoundingBox GetDescribingRectangle() const override;

    /// @brief Возвращает длину стороны
    /// @return Длина стороны
    double GetSide() const
    {
        return side_;
    }

private:
    double side_; ///< Длина стороны квадрата
};

#pragma once

#include <include/figure.h>

/// @brief Класс, представляющий круг
/// Наследуется от Figure, добавляет радиус
class Circle : public Figure
{
public:
    /// @brief Конструктор круга
    /// @param centerX Координата X центра
    /// @param centerY Координата Y центра
    /// @param radius Радиус круга (должен быть положительным)
    /// @param color Цвет круга
    /// @throw std::invalid_argument если радиус <= 0
    Circle(double centerX, double centerY, double radius, Color color);

    /// @brief Вычисляет площадь круга
    /// @return Площадь (π * R²)
    double GetArea() const override;

    /// @brief Возвращает описывающий прямоугольник (квадрат, описанный вокруг круга)
    /// @return BoundingBox с размерами 2R x 2R
    BoundingBox GetDescribingRectangle() const override;

    /// @brief Возвращает радиус круга
    /// @return Радиус
    double GetRadius() const
    {
        return radius_;
    }

private:
    double radius_; ///< Радиус круга
};

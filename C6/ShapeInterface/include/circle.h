#pragma once

#include <include/shape.h>

/// @brief Класс круга
class Circle : public Shape
{
public:
    /// @brief Конструктор круга
    /// @param radius Радиус круга (положительный)
    explicit Circle(double radius);

    /// @brief Вычисляет площадь круга
    /// @return Площадь (π * R²)
    double Square() const override;

    /// @brief Возвращает размеры описывающего квадрата
    /// @return BoundingBoxDimensions с width = height = 2R
    BoundingBoxDimensions Dimensions() const override;

    /// @brief Возвращает строку "Circle"
    /// @return Тип фигуры
    std::string Type() const override;

private:
    double radius_; ///< Радиус круга
};

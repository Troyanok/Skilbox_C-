#pragma once

#include <include/shape.h>

/// @brief Класс прямоугольника
class Rectangle : public Shape
{
public:
    /// @brief Конструктор прямоугольника
    /// @param width Ширина (положительная)
    /// @param height Высота (положительная)
    Rectangle(double width, double height);

    /// @brief Вычисляет площадь прямоугольника
    /// @return Площадь (ширина * высота)
    double Square() const override;

    /// @brief Возвращает размеры описывающего прямоугольника (совпадает с самим прямоугольником)
    /// @return BoundingBoxDimensions с width и height
    BoundingBoxDimensions Dimensions() const override;

    /// @brief Возвращает строку "Rectangle"
    /// @return Тип фигуры
    std::string Type() const override;

private:
    double width_;  ///< Ширина
    double height_; ///< Высота
};

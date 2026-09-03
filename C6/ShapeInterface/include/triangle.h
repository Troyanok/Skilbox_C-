#pragma once

#include <include/shape.h>

/// @brief Класс треугольника (произвольного, заданного тремя сторонами)
class Triangle : public Shape
{
public:
    /// @brief Конструктор треугольника
    /// @param sideA Сторона A
    /// @param sideB Сторона B
    /// @param sideC Сторона C
    /// @throw std::invalid_argument если стороны не образуют треугольник
    Triangle(double sideA, double sideB, double sideC);

    /// @brief Вычисляет площадь по формуле Герона
    /// @return Площадь
    double Square() const override;

    /// @brief Возвращает размеры описывающего квадрата
    /// @return BoundingBoxDimensions с width = height = 2R
    BoundingBoxDimensions Dimensions() const override;

    /// @brief Возвращает строку "Triangle"
    /// @return Тип фигуры
    std::string Type() const override;

private:
    double a_; ///< Сторона A
    double b_; ///< Сторона B
    double c_; ///< Сторона C
};

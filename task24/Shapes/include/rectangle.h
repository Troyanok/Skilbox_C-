#pragma once

#include <include/figure.h>

/// @brief Класс, представляющий прямоугольник
/// Наследуется от Figure, добавляет ширину и высоту
class RectangleFigure : public Figure
{
public:
    /// @brief Конструктор прямоугольника
    /// @param centerX Координата X центра
    /// @param centerY Координата Y центра
    /// @param width Ширина (должна быть положительной)
    /// @param height Высота (должна быть положительной)
    /// @param color Цвет прямоугольника
    /// @throw std::invalid_argument если ширина или высота <= 0
    RectangleFigure(double centerX, double centerY, double width, double height, Color color);

    /// @brief Вычисляет площадь прямоугольника
    /// @return Площадь (ширина * высота)
    double GetArea() const override;

    /// @brief Возвращает описывающий прямоугольник (совпадает с самим прямоугольником)
    /// @return BoundingBox с заданными шириной и высотой
    BoundingBox GetDescribingRectangle() const override;

    /// @brief Возвращает ширину
    /// @return Ширина
    double GetWidth() const
    {
        return width_;
    }

    /// @brief Возвращает высоту
    /// @return Высота
    double GetHeight() const
    {
        return height_;
    }

private:
    double width_;  ///< Ширина прямоугольника
    double height_; ///< Высота прямоугольника
};
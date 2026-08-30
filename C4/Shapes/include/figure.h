#pragma once

#include <iostream>

/// @brief Структура, описывающая описывающий прямоугольник фигуры
struct BoundingBox
{
    double x;      ///< Координата X левого верхнего угла
    double y;      ///< Координата Y левого верхнего угла
    double width;  ///< Ширина прямоугольника
    double height; ///< Высота прямоугольника
};

/// @brief Перечисление цветов фигуры
enum class Color {
    None,  ///< Отсутствие цвета
    Red,   ///< Красный
    Blue,  ///< Синий
    Green  ///< Зелёный
};

/// @brief Базовый абстрактный класс геометрической фигуры
/// Содержит общие данные: координаты центра и цвет
/// Определяет интерфейс для вычисления площади и описывающего прямоугольника
class Figure
{
public:
    /// @brief Конструктор базового класса
    /// @param centerX Координата X центра фигуры
    /// @param centerY Координата Y центра фигуры
    /// @param color Цвет фигуры
    Figure(double centerX, double centerY, Color color)
        : centerX_(centerX), centerY_(centerY), color_(color) {}

    /// @brief Виртуальный деструктор
    virtual ~Figure() = default;

    /// @brief Чисто виртуальный метод для вычисления площади фигуры
    /// @return Площадь фигуры
    virtual double GetArea() const = 0;

    /// @brief Чисто виртуальный метод для получения описывающего прямоугольника
    /// @return Структура BoundingBox с координатами и размерами
    virtual BoundingBox GetDescribingRectangle() const = 0;

    /// @brief Возвращает координату X центра фигуры
    /// @return Координата X
    double GetCenterX() const
    {
        return centerX_;
    }

    /// @brief Возвращает координату Y центра фигуры
    /// @return Координата Y
    double GetCenterY() const
    {
        return centerY_;
    }

    /// @brief Возвращает цвет фигуры
    /// @return Значение перечисления Color
    Color GetColor() const
    {
        return color_;
    }

protected:
    double centerX_; ///< Координата X центра
    double centerY_; ///< Координата Y центра
    Color color_;    ///< Цвет фигуры
};

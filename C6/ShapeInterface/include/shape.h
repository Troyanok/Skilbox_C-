#pragma once

#include <string>

/// @brief Структура размеров описывающего прямоугольника
struct BoundingBoxDimensions
{
    double width;  ///< Ширина
    double height; ///< Высота
};

/// @brief Абстрактный интерфейс геометрической фигуры
class Shape
{
public:
    /// @brief Виртуальный деструктор
    virtual ~Shape() = default;

    /// @brief Возвращает площадь фигуры
    /// @return Площадь
    virtual double Square() const = 0;

    /// @brief Возвращает размеры описывающего прямоугольника
    /// @return BoundingBoxDimensions
    virtual BoundingBoxDimensions Dimensions() const = 0;

    /// @brief Возвращает строковое название типа фигуры
    /// @return Название типа
    virtual std::string Type() const = 0;
};

/// @brief Выводит параметры фигуры: тип, площадь, размеры описывающего прямоугольника
/// @param shape Указатель на объект фигуры
void PrintParams(Shape* shape);

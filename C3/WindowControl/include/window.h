#pragma once

#include <iostream>

/// @brief Класс пользовательского окна
class Window
{
public:
    /// @brief Конструктор
    Window();

    /// @brief Конструктор с параметрами
    /// @param x Начальная координата OX
    /// @param y Начальная координата OY
    /// @param width Высота окна
    /// @param height Ширина окна
    Window(int x, int y, int width, int height);

    /// @brief Деструктор по умолчанию
    ~Window() = default;

    /// @brief Передвинуть окно пользователя
    /// @param dx Смещение по оси OX
    /// @param dy Смещение по оси OY
    /// @return true - получилось переместить, иначе - false
    bool MoveWindow(int dx, int dy);

    /// @brief Изменить размер окна
    /// @param newWidth Новая высота
    /// @param newHeight Новая ширина
    /// @return true - получилось изменить размер окна, иначе - false
    bool ResizeWindow(int newWidth, int newHeight);

    /// @brief Получить начальную координату OX
    /// @return Начальная координата OX
    int GetX() const;

    /// @brief Получить начальную координату OY
    /// @return Начальная координата OY
    int GetY() const;

    /// @brief Получить высоту окна
    /// @return Высота окна
    int GetWidth() const;

    /// @brief Получить ширину окна
    /// @return Ширина окна
    int GetHeight() const;

private:
    int x_;         ///< начальная координата OX
    int y_;         ///< начальная координата OY
    int width_;     ///< Высота 
    int height_;    ///< Ширина
};

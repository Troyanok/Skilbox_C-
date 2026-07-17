#pragma once

#include <include/window.h>

/// @brief Класс для симулятора окна
class Screen
{
public:
    /// @brief Конструктор по умолчанию
    Screen() = default;
    
    /// @brief Деструктор по умолчанию
    ~Screen() = default;

    /// @brief Получить размеры окна приложения
    void GetUserWindowParams();

    /// @brief Обработать команды пользователя по взаимодействию с окном
    void WorkScreenCommand();

private:
    /// @brief Напечатать окно и приложение
    void PrintDisplay();

private:
    Window userWin_; ///< объект-класса пользовательского окна
};

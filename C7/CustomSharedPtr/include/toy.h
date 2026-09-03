#pragma once

#include <string>
#include <iostream>

/// @brief Класс игрушки
class Toy
{
public:
    /// @brief Конструктор
    /// @param name Имя игрушки
    Toy(const std::string& name);

    /// @brief Деструктор Выводит сообщение об удалении
    ~Toy();

    /// @brief Возвращает имя игрушки
    /// @return Имя
    std::string GetName() const;

private:
    std::string name_; ///< Имя
};

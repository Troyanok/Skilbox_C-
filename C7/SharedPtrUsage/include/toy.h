#pragma once

#include <string>
#include <iostream>

/// @brief Класс игрушки
class Toy
{
public:
    /// @brief Конструктор игрушки
    /// @param name Имя игрушки
    Toy(const std::string& name)
    {
        name_ = name;
    }

    /// @brief Деструктор Выводит сообщение об удалении
    ~Toy()
    {
        std::cout << "Toy " << name_ << " was dropped" << std::endl;
    }

    /// @brief Возвращает имя игрушки
    /// @return Имя
    std::string GetName() const
    {
        return name_;
    }

private:
    std::string name_; ///< Имя игрушки
};

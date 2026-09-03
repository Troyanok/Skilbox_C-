#pragma once

#include <string>
#include <vector>
#include <memory>
#include <include/talent.h>

/// @brief Класс собаки, которой можно добавлять таланты
class Dog
{
public:
    /// @brief Конструктор собаки
    /// @param name Имя собаки
    explicit Dog(const std::string& name)
    {
        name_ = name;
    }

    /// @brief Добавляет талант собаке
    /// @param talent Умный указатель на объект таланта (наследник Talent)
    void AddTalent(std::unique_ptr<Talent> talent)
    {
        talents_push_back(std::move(talent));
    }

    /// @brief Выводит имя собаки и список всех её талантов
    void ShowTalents() const;

    /// @brief Возвращает имя собаки
    /// @return Имя
    std::string GetName() const
    {
        return name_;
    }

private:
    std::string name_;                              ///< Имя собаки
    std::vector<std::unique_ptr<Talent>> talents_; ///< Вектор талантов
};

#pragma once

#include <memory>
#include <string>
#include <include/toy.h>

/// @brief Класс собаки, которая может подбирать и бросать игрушки
class Dog
{
public:
    /// @brief Конструктор собаки
    /// @param name Имя собаки
    explicit Dog(const std::string& name)
    {
        name_ = name;
    }

    /// @brief Подбирает игрушку (если возможно)
    /// @param toy Умный указатель на игрушку
    void GetToy(std::shared_ptr<Toy> toy);

    /// @brief Бросает текущую игрушку
    void DropToy();

    /// @brief Возвращает имя собаки
    /// @return Имя
    std::string GetName() const
    {
        return name_;
    }

    /// @brief Проверяет, есть ли у собаки игрушка
    /// @return true если есть
    bool HasToy() const
    {
        return currentToy_ != nullptr;
    }

private:
    std::string name_;                ///< Имя собаки
    std::shared_ptr<Toy> currentToy_; ///< Текущая игрушка (может быть nullptr)
};

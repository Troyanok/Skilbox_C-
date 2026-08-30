#pragma once

#include <string>
#include <vector>
#include <include/common.h>

class Team; // Предварительное объявление

/// @brief Класс, представляющий менеджера среднего звена
class Manager
{
public:
    /// @brief Конструктор менеджера
    /// @param name Имя менеджера
    /// @param id Уникальный идентификатор
    Manager(const std::string& name, int id)
    {
        name_ = name;
        id_ = id;
        team_ = nullptr;
    }

    /// @brief Устанавливает связь с командой
    /// @param team Указатель на команду
    void SetTeam(Team* team)
    {
        team_ = team;
    }

    /// @brief Обрабатывает директиву от главы компании
    /// @param directive Целочисленный идентификатор директивы
    void ProcessDirective(int directive);

    /// @brief Возвращает имя менеджера
    /// @return Имя
    std::string GetName() const
    {
        return name_;
    }

    /// @brief Возвращает идентификатор менеджера
    /// @return ID
    int GetId() const
    {
        return id_;
    }

private:
    std::string name_; ///< Имя менеджера
    int id_;           ///< Идентификатор
    Team* team_;       ///< Указатель на команду
};
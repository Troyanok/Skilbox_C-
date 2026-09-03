#pragma once

#include <string>

/// @brief Базовый класс таланта
class Talent
{
public:
    /// @brief Виртуальный деструктор
    virtual ~Talent() = default;

    /// @brief Возвращает название таланта
    /// @return Название таланта (например, "Swim", "Dance", "Count")
    virtual std::string GetTalentName() const = 0;
};

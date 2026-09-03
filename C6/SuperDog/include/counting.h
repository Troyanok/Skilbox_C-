#pragma once

#include <include/talent.h>

/// @brief Талант «Счёт»
class Counting : public Talent
{
public:
    /// @brief Возвращает название таланта
    /// @return Строка "Count"
    std::string GetTalentName() const override
    {
        return "Count";
    }
};

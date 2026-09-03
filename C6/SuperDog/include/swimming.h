#pragma once

#include <include/talent.h>

/// @brief Талант «Плавание»
class Swimming : public Talent
{
public:
    /// @brief Возвращает название таланта
    /// @return Строка "Swim"
    std::string GetTalentName() const override
    {
        return "Swim";
    }
};

#pragma once

#include <include/talent.h>

/// @brief Талант «Танцы»
class Dancing : public Talent
{
public:
    /// @brief Возвращает название таланта
    /// @return Строка "Dance"
    std::string GetTalentName() const override
    {
        return "Dance";
    }
};

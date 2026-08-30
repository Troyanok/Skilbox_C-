#pragma once

#include <iostream>
#include <string>

/// @brief Класс для хранения информации о контакте
class Contact
{
public:
    /// @brief Конструктор по умолчанию
    Contact();

    /// @brief Конструктор 
    Contact(const std::string& name, const std::string& phone);

    /// @brief Деструктор по умолчанию
    ~Contact() = default;

    /// @brief Получить имя контакта
    std::string GetContactName() const;

    /// @brief Получить номер контакта
    std::string GetPhoneName() const;

private:
    std::string name_;  ///< номер контакта
    std::string phone_; ///< номер телефона
};

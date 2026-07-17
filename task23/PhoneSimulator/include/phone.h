#pragma once

#include <include/contact.h>

#include <iostream>
#include <string>
#include <map>
#include <vector>

/// @brief Класс симулятора телефона
class PhoneSim
{
public:
    /// @brief Конструктор
    PhoneSim();

    /// @brief Деструктор
    ~PhoneSim() = default;

    /// @brief Добавить контакт в телефон
    /// @param phone Номер телефона
    /// @param name Имя контакта
    void AddPhone(const std::string& phone, const std::string& name);

    /// @brief Позвонить контакту
    /// @param str Номер телефона или имя контакта
    void CallPhone(const std::string& str);

    /// @brief Написать смс контакту
    /// @param str Номер телефона или имя контакта
    void WriteSms(const std::string& str);

private:
    /// @brief Найти телефон в контактной книге
    /// @param str Номер телефона или имя  контакта
    /// @return true Найден был контакт, иначе - false
    bool FindPhoneFromList(const std::string& str);

private:
    std::vector<Contact> phoneList_; ///< Телефонная книга
    Contact currentElem_;            ///< Текущий контакт
};

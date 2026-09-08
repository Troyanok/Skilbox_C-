#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <algorithm>

/// @brief Шаблонная структура пары ключ-значение
/// @tparam KeyType Тип ключа
/// @tparam ValueType Тип значения
template <typename KeyType, typename ValueType>
struct KeyValuePair
{
    KeyType key;
    ValueType value;
};

/// @brief Шаблонный класс реестра
/// @tparam KeyType Тип ключа
/// @tparam ValueType Тип значения
template <typename KeyType, typename ValueType>
class Registry
{
public:
    /// @brief Добавляет элемент с ключом
    /// @param key Ключ
    /// @param value Значение
    void Add(const KeyType& key, const ValueType& value)
    {
        items_.push_back({key, value});
    }

    /// @brief Удаляет все элементы с заданным ключом
    /// @param key Ключ
    void Remove(const KeyType& key)
    {
        items_.erase(
            std::remove_if(items_.begin(), items_.end(),
                [&key](const KeyValuePair<KeyType, ValueType>& item)
                {
                    return item.key == key;
                }),
            items_.end());
    }

    /// @brief Выводит все элементы с ключами
    void Print() const
{
        if (items_.empty())
        {
            std::cout << "Registry is empty." << std::endl;
            return;
        }
        for (const auto& item : items_)
        {
            std::cout << "Key: " << item.key << ", Value: " << item.value << std::endl;
        }
    }

    /// @brief Находит и выводит элементы по ключу
    /// @param key Ключ
    void Find(const KeyType& key) const
{
        bool found = false;
        for (const auto& item : items_)
        {
            if (item.key == key)
            {
                std::cout << "Value: " << item.value << std::endl;
                found = true;
            }
        }
        if (!found)
        {
            std::cout << "No items with this key." << std::endl;
        }
    }

private:
    std::vector<KeyValuePair<KeyType, ValueType>> items_;
};

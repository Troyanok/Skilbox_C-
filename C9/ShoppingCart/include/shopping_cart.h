#pragma once

#include <map>
#include <string>
#include <stdexcept>

/// @brief Класс, моделирующий корзину онлайн-магазина
class ShoppingCart
{
public:
    /// @brief Добавляет товар в базу данных магазина
    /// @param article Артикул товара
    /// @param quantity Количество
    /// @throw std::invalid_argument если количество <= 0
    void AddToStore(const std::string& article, int quantity);

    /// @brief Добавляет товар в корзину
    /// @param article Артикул товара
    /// @param quantity Количество
    /// @throw std::invalid_argument при некорректных данных
    void AddToCart(const std::string& article, int quantity);

    /// @brief Удаляет товар из корзины
    /// @param article Артикул товара
    /// @param quantity Количество
    /// @throw std::invalid_argument при некорректных данных
    void RemoveFromCart(const std::string& article, int quantity);

    /// @brief Выводит содержимое корзины
    void PrintCart() const;

private:
    std::map<std::string, int> store_; ///< База данных магазина
    std::map<std::string, int> cart_;  ///< Корзина
};

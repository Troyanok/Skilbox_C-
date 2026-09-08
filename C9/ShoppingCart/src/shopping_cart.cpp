#include "include/shopping_cart.h"
#include <iostream>

void ShoppingCart::AddToStore(const std::string& article, int quantity)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Quantity must be positive");
    }
    store_[article] += quantity;
}

void ShoppingCart::AddToCart(const std::string& article, int quantity)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Quantity must be positive");
    }
    if (store_.find(article) == store_.end())
    {
        throw std::invalid_argument("Article not found in store");
    }
    if (store_[article] < quantity)
    {
        throw std::invalid_argument("Not enough items in store");
    }
    store_[article] -= quantity;
    cart_[article] += quantity;
    std::cout << "Added " << quantity << " of " << article << " to cart." << std::endl;
}

void ShoppingCart::RemoveFromCart(const std::string& article, int quantity)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Quantity must be positive");
    }
    auto it = cart_.find(article);
    if (it == cart_.end())
    {
        throw std::invalid_argument("Article not found in cart");
    }
    if (it->second < quantity)
    {
        throw std::invalid_argument("Not enough items in cart");
    }
    it->second -= quantity;
    store_[article] += quantity;
    if (it->second == 0)
    {
        cart_.erase(it);
    }
    std::cout << "Removed " << quantity << " of " << article << " from cart." << std::endl;
}

void ShoppingCart::PrintCart() const
{
    if (cart_.empty())
    {
        std::cout << "Cart is empty." << std::endl;
        return;
    }
    std::cout << "Cart contents:" << std::endl;
    for (const auto& [article, qty] : cart_)
    {
        std::cout << "  " << article << ": " << qty << std::endl;
    }
}

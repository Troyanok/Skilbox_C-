#include <iostream>
#include <string>
#include "include/shopping_cart.h"

int main()
{
    ShoppingCart cart;
    std::string command;
    std::cout << "Commands: add_store, add, remove, print, exit" << std::endl;

    while (true)
    {
        std::cout << "> ";
        std::cin >> command;
        try
           {
            if (command == "add_store")
            {
                std::string article;
                int qty;
                std::cin >> article >> qty;
                cart.AddToStore(article, qty);
            }
            else if (command == "add")
            {
                std::string article;
                int qty;
                std::cin >> article >> qty;
                cart.AddToCart(article, qty);
            }
            else if (command == "remove")
            {
                std::string article;
                int qty;
                std::cin >> article >> qty;
                cart.RemoveFromCart(article, qty);
            }
            else if (command == "print")
            {
                cart.PrintCart();
            }
            else if (command == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command" << std::endl;
            }
        }
        catch (const std::exception& e)
           {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}

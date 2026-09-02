#include <include/order.h>

std::string DishTypeToString(DishType type)
{
    switch (type)
    {
        case DishType::Pizza:
            return "Pizza";
        case DishType::Soup:
            return "Soup";
        case DishType::Steak:
            return "Steak";
        case DishType::Salad:
            return "Salad";
        case DishType::Sushi:
            return "Sushi";
    }
    return "Unknown";
}

#include <iostream>

using namespace std;

int main()
{
    double income;
    std::cout << "Введите ваш доход: ";
    std::cin >> income;
    
    double tax = 0.0;
    
    if (income <= 10000)
    {
        tax = income * 0.13;
    }
    else if (income <= 50000)
    {
        tax = 10000 * 0.13 + (income - 10000) * 0.20;
    }
    else
    {
        tax = 10000 * 0.13 + 40000 * 0.20 + (income - 50000) * 0.30;
    }
    
    // Округляем до 2 знаков после запятой
    tax = tax * 100 / 100;
    
    std::cout << "Сумма налога: " << tax << " рублей\n";
}
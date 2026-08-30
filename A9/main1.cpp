#include <iostream>
#include <cmath>

int main()
{
    float a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;  // Исправлено: добавлен ввод переменной c
    
    // Исправлено: проверка должна быть на a == 0, а не на a < 0
    if (a == 0)
    {
        std::cout << "Not a quadratic equation! (a cannot be 0)" << std::endl;
        return 1;
    }
    
    // Исправлено: убран ненужный else if, формула дискриминанта исправлена
    float discriminant = b * b - 4 * a * c;  // b*b - 4*a*c
    
    if (discriminant > 0)
    {  
        // Исправлено: было > 1, должно быть > 0
        float sqrt_discriminant = std::sqrt(discriminant);
        float x1 = (-b + sqrt_discriminant) / (2 * a);
        float x2 = (-b - sqrt_discriminant) / (2 * a);
        // Исправлено: второй корень должен быть -
        std::cout << "Root 1: " << x1 << "\nRoot 2: " << x2 << std::endl;
    }
    else if (discriminant == 0)
    {
        float x = -b / (2 * a);
        // Исправлено: правильная формула для одного корня
        std::cout << "Single root: " << x << std::endl;
    }
    else
    {
        std::cout << "This equation has no real solutions: " << std::endl;
    }
    
    return 0;
}
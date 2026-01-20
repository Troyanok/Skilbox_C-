#include <iostream>
#include <cassert>

using namespace std;

float travelTime(float distance, float speed)
{
    // Проверяем, что скорость положительна
    assert(speed > 0 && "Скорость должна быть положительной!");
    
    return distance / speed;
}

int main()
{
    float distance, speed;
    
    cout << "Введите расстояние (км): ";
    cin >> distance;
    
    cout << "Введите скорость (км/ч): ";
    cin >> speed;
    
    // Вызов функции с assert
    float time = travelTime(distance, speed);
    
    cout << "Время в пути: " << time << " часов" << endl;
    
    cout << "Тест assert с отрицательной скоростью:" << endl;
    float badTime = travelTime(100, -50);  // Здесь произойдет падение
    
    return 0;
}
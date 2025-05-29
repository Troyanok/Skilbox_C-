#include <iostream>

using namespace std;

int main()
{ 
    int lap = 4; 
    int engine = 254; 
    int wheels = 93; 
    int steerinWheel = 49; 
    int wind = 21; 
    int rain = 17;
    int speed = (engine + wheels + steerinWheel) - (wind + rain); 

    cout << "===================\n"; 
    cout << "Супер гонки. Круг " << lap << "\n"; 
    cout << "===================\n"; 
    cout << "Шумахер (" << speed << ")\n"; 
    cout << "===================\n"; 
    cout << "Водитель: Шумахер\n"; 
    cout << "Скорость: " << speed << "\n"; 
    cout << "-------------------\n"; 
    cout << "Оснащение\n"; 
    cout << "Двигатель: +" << engine << "\n"; 
    cout << "Колеса: +" << wheels << "\n"; 
    cout << "Руль: +" << steerinWheel << "\n"; 
    cout << "-------------------\n"; 
    cout << "Действия плохой погоды\n"; 
    cout << "Ветер: -" << wind << "\n"; 
    cout << "Дождь: -" << rain << "\n";
    
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int kilometers;
    
    cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
    cin >> kilometers;
    
    if (kilometers <= 0) {
        cout << "Ошибка: количество километров должно быть положительным!" << endl;
        return 1;
    }
    
    int totalSeconds = 0;
    
    for (int i = 1; i <= kilometers; i++)
    {
        int pace;
        cout << "Какой у тебя был темп на километре " << i << "? ";
        cin >> pace;
        
        if (pace <= 0)
        {
            cout << "Ошибка: темп должен быть положительным!" << endl;
            i--; 
            continue;
        }
        
        totalSeconds += pace;
    }
    
    int averageSeconds = static_cast<int>(round(static_cast<float>(totalSeconds) / kilometers));
    int minutes = averageSeconds / 60;
    int seconds = averageSeconds % 60;
    
    cout << "Твой средний темп за тренировку: " << minutes << " минуты " << seconds << " секунд." << endl;
    
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

const int APARTMENTS_COUNT = 10;

int main()
{
    string residents[APARTMENTS_COUNT];
    
    cout << "Введите фамилии жильцов 10 квартир (от 1 до 10):\n";
    for (int i = 0; i < APARTMENTS_COUNT; i++)
    {
        cout << "Квартира " << (i + 1) << ": ";
        cin >> residents[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        int apartmentNumber;
        cout << "Введите номер квартиры для поиска (" << (i + 1) << " из 3): " << endl;
        cin >> apartmentNumber;
        
        // Проверка корректности номера квартиры
        if ((apartmentNumber < 1) || (apartmentNumber > APARTMENTS_COUNT))
        {
            cout << "Ошибка: некорректный номер квартиры! Допустимые значения: 1-" 
                 << APARTMENTS_COUNT << endl;
        }
        else
        {
            // Вывод фамилии жильца (индексы в массиве начинаются с 0)
            cout << "В квартире " << apartmentNumber 
                 << " проживает: " << residents[apartmentNumber - 1] << endl;
        }
    }
    
    return 0;
}
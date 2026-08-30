#include <iostream>

using namespace std;

const int NUMBERS_COUNT = 15;

int main()
{
    double numbers[NUMBERS_COUNT];
    
    // Чтение чисел
    cout << "Введите " << NUMBERS_COUNT << " дробных чисел:" << endl;
    for (int i = 0; i < NUMBERS_COUNT; i++)
    {
        cout << "Число " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Сортировка выбором (сложность O(n²), но простая реализация)
    for (int i = 0; i < NUMBERS_COUNT - 1; i++)
    {
        // Находим максимальный элемент в неотсортированной части
        int maxIndex = i;
        for (int j = i + 1; j < NUMBERS_COUNT; j++)
        {
            if (numbers[j] > numbers[maxIndex])
            {
                maxIndex = j;
            }
        }
        
        // Меняем местами текущий элемент с максимальным
        if (maxIndex != i)
        {
            double temp = numbers[i];
            numbers[i] = numbers[maxIndex];
            numbers[maxIndex] = temp;
        }
    }
    
    // Вывод отсортированных чисел
    cout << "Числа в порядке убывания:" << endl;
    for (int i = 0; i < NUMBERS_COUNT; i++)
    {
        cout << numbers[i];
        if (i < NUMBERS_COUNT - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
    
    return 0;
}
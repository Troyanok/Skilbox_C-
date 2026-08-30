#include <iostream>

using namespace std;

int main()
{
    int mansCount;
    int barbersCount;

    cout << "************** Барбершоп-калькулятор **************\n";
    cout << "Введите число мужчин в городе: ";
    cin >> mansCount;

    cout << "Сколько уже барберов удалось нанять? ";
    cin >> barbersCount;

    // Константы для расчетов
    const int mansPerBarberPerDay = 8;  // 8 клиентов в день
    const int daysPerMonth = 30;
    const int mansPerBarberPerMonth = mansPerBarberPerDay * daysPerMonth;

    // Расчет необходимого количества барберов с использованием %
    int requiredBarbersCount = mansCount / mansPerBarberPerMonth;
    if (mansCount % mansPerBarberPerMonth != 0)
    {
        requiredBarbersCount++;
    }

    cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";

    // Сравнение с имеющимся количеством барберов
    if (requiredBarbersCount > barbersCount)
    {
        cout << "Нужно больше барберов!!!\n";
    }
    else if (requiredBarbersCount == barbersCount)
    {
        cout << "Барберов ровно столько, сколько нужно!!!\n";
    }
    else
    {
        cout << "Барберов хватает!!!\n";
        if (barbersCount >= 2 * requiredBarbersCount)
        {
            cout << "У вас работает в два раза больше барберов, чем это нужно!!!\n";
        }
    }

    return 0;
}
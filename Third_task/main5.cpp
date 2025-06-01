#include <iostream>

using namespace std;

int main()
{
    int firstNumber;
    int secondNumber;

    cout << "Введите первое число: ";
    cin >> firstNumber;

    cout << "Введите второе число: ";
    cin >> secondNumber;

    cout << "-----Проверяем----- " << endl;

    if (firstNumber % secondNumber == 0)
    {
        cout << "Да, "<< firstNumber << " делится на " << secondNumber << " без остатка!" << endl;
    }
    else
    {
        cout << "Нет, "<< firstNumber << " не делится на " << secondNumber << " без остатка!" << endl;
    }
    return 0;
}
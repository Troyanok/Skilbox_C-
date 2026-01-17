#include <iostream>

using namespace std;

int main()
{
    int firstNumber;
    int secondNumber;
    int sumInput;

    cout << "Введите первое число: ";
    cin >> firstNumber;

    cout << "Введите второе число: ";
    cin >> secondNumber;

    cout << "Введите их сумму: ";
    cin >> sumInput;

    cout << "-----Проверяем-----" << endl;
    
    if (sumInput == (firstNumber + secondNumber))
    {
        cout << "Верно!" << endl;
    }
    else
    {
        cout << "Ошибка! Верный результат: " << firstNumber + secondNumber << endl;
    }
    
    return 0;
}
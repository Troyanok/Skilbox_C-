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

    cout << "-----Проверяем-----" << endl;

    if (firstNumber == secondNumber)
    {
        cout << "Числа равны!" << endl;
    }
    else
    {
        cout << "Наименьшее число: " << (firstNumber > secondNumber ? secondNumber : firstNumber) << endl; 
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long firstValue, secondValue;

    cout << "Введите числитель: ";
    cin >> firstValue;
    cout << "Введите знаменатель: ";
    cin >> secondValue;

    if (secondValue == 0)
    {
        cout << "Знаменатель не может быть нулем." << endl;
        return 1;
    }

    int sign = 1;

    if (((firstValue < 0) && (secondValue > 0)) || ((firstValue > 0) && (secondValue < 0)))
    {
        sign = -1;
    }

    long a = abs(firstValue);
    long b = abs(secondValue);

    while (b != 0)
    {
        long temp = b;
        b = a % b;
        a = temp;
    }

    long gcd = a;

    firstValue /= gcd;
    secondValue /= gcd;

    if ((sign < 0) && (firstValue != 0))
    {
        firstValue = -firstValue;
    }

    cout << "Результат: " << firstValue << " / " << secondValue << endl;
    return 0;
}
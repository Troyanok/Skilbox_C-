#include <iostream>

using namespace std;

const int MAX_YEARS = 10000;

int main()
{
    int depositAmount, amount;
    int procent;

    cout << "Введите размер вклада: ";
    cin >> depositAmount;
    cout << "Введите процентную ставку: ";
    cin >> procent;
    cout << "Введите желаемую сумму: ";
    cin >> amount;

    if ((depositAmount <= 0) || (procent < 0) || (amount <= 0))
    {
        cout << "Все значения должны быть положительными." << endl;
        return -1;
    }

    int years = 0;
    long long current = depositAmount;
    long long addition;

    if (current >= amount)
    {
        cout << "Придётся подождать: 0 лет" << endl;
        return 0;
    }

    while ((current < amount) && (years < MAX_YEARS))
    {
        addition = (current * procent) / 100;
        if (addition <= 0)
        {
            break;
        }

        current += addition;
        years++;
    }

    if (current >= amount)
    {
        cout << "Придётся подождать: " << years << " лет" << endl;
    }
    else
    {
        cout << "Невозможно достичь желаемой суммы." << endl;
        return -1;
    }

    return 0;
}
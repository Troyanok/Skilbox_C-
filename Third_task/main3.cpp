#include <iostream>

using namespace std;

int main()
{
    int inputNumber;

    cout << "Введите число: ";
    cin >> inputNumber;

    if (inputNumber % 2 == 0)
    {
        cout << "Число " << inputNumber << " чётное." << endl;
    }
    else
    {
        cout << "Число " << inputNumber << " нечётное." << endl;
    }

    return 0;
}
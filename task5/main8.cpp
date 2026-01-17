#include <iostream>
#include <string>

using namespace std;

const int LOW_BOUND = 0;
const int HIGH_BOUND = 63;

int main()
{
    int lowValue = LOW_BOUND;
    int highValue = HIGH_BOUND;
    int midValue;
    string answer;

    cout << "Загадайте число от " << LOW_BOUND << " до " << HIGH_BOUND << " (включительно)." << endl;

    while (lowValue < highValue)
    {
        midValue = (lowValue + highValue) / 2;
        cout << "Ваше число больше " << midValue << "? (да/нет): ";
        cin >> answer;

        if (answer == "да")
        {
            lowValue = midValue + 1;
        }
        else if (answer == "нет")
        {
            highValue = midValue;
        }
        else
        {
            cout << "Пожалуйста, ответьте 'да' или 'нет'." << endl;
        }
    }

    cout << "Ваше число: " << lowValue << endl;
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int countExp;
    int level = 1;

    cout << "Введите число очков опыта: ";
    cin >> countExp;

    cout << "-----Считаем----- " << endl;

    level = (countExp >= 5000) ? 4 : 3;
    level = (countExp < 2500) ? 2 : level;
    level = (countExp < 1000) ? 1 : level;

    cout << "Ваш уровень: " << level << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int beginHeight = 100;
    int dailyGrowth = 50;
    int nightFade   = 20;

    cout << "Высота бамбука на 3ий день: " << beginHeight + 3*dailyGrowth - 2*nightFade << "см." << endl;

    return 0;
}
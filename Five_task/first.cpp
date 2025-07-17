#include <iostream>

using namespace std;

int main()
{
     int inputHours;
     cout << "Введите, который час: ";
     cin >> inputHours;

     if ((inputHours < 0) || (inputHours > 23))
     {
          cout << "В сутках 24-часа. Допустимый диапазон часов: [0, 23]" << endl;
          return -1;
     }

     if (inputHours == 0)
     {
          cout << "Полночь! Не будет ку-ку..." << endl;
          return 0;
     }

     for (int i = 0; i < inputHours; i++)
     {
          cout << "Ку-ку!" << endl;
     }

     return 0;
}

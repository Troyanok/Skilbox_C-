#include <iostream>
#include <string.h>

using namespace std;

int main()
{
     string inputName;
     int inputArrears;
     int inputValue;

     cout << "Укажите имя задолжника: ";
     cin >> inputName;

     cout << "Укажите сумму долга: ";
     cin >> inputArrears;

     if (inputArrears <= 0)
     {
          cout << "Сумма задолженности должна быть положительной!" << endl;
          return -1;
     }

     while (inputArrears > 0)
     {
          cout << "---------------------------" << endl;
          cout << "Текущая сумма задолженности: " << inputArrears << endl;
          cout << "Введите сумму поступления: ";
          cin >> inputValue;
          cout << endl;

          if (inputValue <= 0)
          {
               cout << "Полученная сумма может быть только положительной!" << endl;
          }
          else
          {
               inputArrears -= inputValue;
          }
     }

     cout << "Долг был погашен!" << endl;

     if (inputArrears < 0)
     {
          cout << "Остаток на счету: " << abs(inputArrears) << endl;
     }

     return 0;
}

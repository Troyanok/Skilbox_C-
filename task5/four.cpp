#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
     size_t countSymbols;
     string inputValue;

     cout << "Введите количество цифр в билете: ";
     cin >> countSymbols;

     if (countSymbols < 1)
     {
          cout << "Для проверки билета общее количество символов должно быть больше 0!" << endl;
          return -1;
     }

     if (countSymbols % 2 != 0)
     {
          cout << "Для проверки билета общее количество символов должно быть чётным!" << endl;
          return -1;
     }

     cout << "Введите номер билета: ";
     cin >> inputValue;

     if (inputValue.length() > countSymbols)
     {
          cout << "Количество цифр в билете больше " << countSymbols << ", проверить не получится..." << endl;
          return -1;
     }
     else if (inputValue.length() < countSymbols - 1)
     {
          cout << "Количество цифр в билете меньше " << countSymbols << ", проверить не получится..." << endl;
          return -1;
     }

     size_t half = countSymbols / 2;
     int sum1 {0}, sum2 {0};

     for (size_t i = 0; i < half; i++)
     {
          if ((inputValue[i] < '0') || (inputValue[i] > '9'))
          {
               cout << "Введённый символ не численный из диапазона [0, 9]" << endl;
               return -1;
          }
          sum1 += inputValue[i] - '0';
     }

     for (size_t i = half; i < countSymbols; i++)
     {
          if ((inputValue[i] < '0') || (inputValue[i] > '9'))
          {
               cout << "Введённый символ не численный из диапазона [0, 9]" << endl;
               return -1;
          }
          sum2 += inputValue[i] - '0';
     }

     if (sum1 == sum2)
     {
          std::cout << "Билет счастливый!" << std::endl;
     } else {
          std::cout << "Повезёт в следующий раз!" << std::endl;
     }

     return 0;
}

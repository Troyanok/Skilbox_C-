#include <iostream>
#include <string.h>

using namespace std;

int main()
{
     string inputValue;

     cout << "Введите число: ";
     cin >> inputValue;
     cout << inputValue.length() << endl;

     if (inputValue.length() >= 10)
     {
          cout << "Тип данных int вмещает в себе числа с количеством цифр меньше 10!" << endl;
          return -1;
     }

     int value = abs(stoi(inputValue));
     int countSymbols = 1;

     while (value / 10 > 0)
     {
          countSymbols += 1;
          value /= 10;
     }

     cout << "Цифр в числе: " << countSymbols << endl;

     return 0;
}

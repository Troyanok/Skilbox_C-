#include <iostream>
#include <string>

using namespace std;

// Перечисление нот с битовыми масками
enum Note
{
     DO  = 1 << 0,  // 1
     RE  = 1 << 1,  // 2
     MI  = 1 << 2,  // 4
     FA  = 1 << 3,  // 8
     SOL = 1 << 4,  // 16
     LA  = 1 << 5,  // 32
     SI  = 1 << 6   // 64
};

int main()
{
     string chord;
     cout << "Введите аккорд (цифры 1-7): ";
     cin >> chord;

     int mask = 0; // битовая маска аккорда

     // Формируем маску, обрабатывая каждый символ строки
     for (char c : chord)
     {
          if (c >= '1' && c <= '7')
          {
               int index = c - '1';          // индекс ноты (0 для DO, ..., 6 для SI)
               mask |= (1 << index);         // устанавливаем соответствующий бит
          }
     }

     // Вывод нот аккорда
     cout << "Аккорд содержит ноты: ";
     if (mask & DO) 
     {
          cout << "DO ";
     }
     if (mask & RE)
     {
          cout << "RE ";
     }
     if (mask & MI)
     {
          cout << "MI ";
     }
     if (mask & FA)
     {
          cout << "FA ";
     }
     if (mask & SOL)
     {
          cout << "SOL ";
     }
     if (mask & LA)
     {
          cout << "LA ";
     }
     if (mask & SI)
     {
          cout << "SI ";
     }
     
     cout << endl;

     return 0; 
}
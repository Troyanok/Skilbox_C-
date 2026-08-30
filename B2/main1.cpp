#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int vector_size;
   cout << "Введите размер вектора: ";
   cin >> vector_size;
   
   vector<int> vec;
   vec.reserve(vector_size);
   
   cout << "Введите числа для вектора: ";
   for (int i = 0; i < vector_size; i++)
   {
      int num;
      cin >> num;
      vec.push_back(num);
   }
   
   int x;
   cout << "Введите число для удаление: ";
   cin >> x;
   
   // Удаляем все вхождения X in-place
   int delete_index = 0; // Указатель на позицию для записи
   
   for (int read_idx = 0; read_idx < vec.size(); read_idx++)
   {
      if (vec[read_idx] != x)
      {
         vec[delete_index] = vec[read_idx];
         delete_index++;
      }
   }
   
   // Удаляем лишние элементы с конца с помощью pop_back()
   while (vec.size() > delete_index)
   {
      vec.pop_back();
   }
   
   // Выводим результат
   cout << "Результат: ";
   for (int i = 0; i < vec.size(); i++)
   {
      cout << vec[i];
      if (i < vec.size() - 1) {
         cout << " ";
      }
   }
   cout << endl;
   
   return 0;
}
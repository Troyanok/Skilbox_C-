#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    // Создаем вектор фиксированного размера 20
    vector<int> vec(20);
    
    int next_index = 0; // Индекс для следующей записи
    int count = 0;      // Количество записанных элементов
    
    while (true)
    {
        int number;
        cout << "Входящие данные: ";
        cin >> number;
        
        if (number == -1)
        {
            // Вывод содержимого хранилища в порядке добавления
            cout << "Результат: ";
            
            if (count == 20)
            {
                // Если хранилище полное, начинаем выводить с next_index
                for (int i = 0; i < 20; i++)
                {
                    int index = (next_index + i) % 20;
                    cout << vec[index];
                    if (i < 19)
                    {
                        cout << " ";
                    }
                }
            }
            else
            {
                // Если хранилище не полное, выводим от 0 до count-1
                for (int i = 0; i < count; i++)
                {
                    cout << vec[i];
                    if (i < count - 1)
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        else
        {
            // Добавляем число в хранилище
            vec[next_index] = number;
            next_index = (next_index + 1) % 20; // Кольцевой буфер
            
            // Увеличиваем счетчик, но не более 20
            if (count < 20)
            {
                count++;
            }
        }
    }
    
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int height;

    cout << "Введите высоту елочки: ";
    cin >> height;
   
    if (height <= 0)
    {
        cout << "Ошибка: высота должна быть положительным числом!" << endl;
        return 1;
    }
    
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "#";
        }
        
        cout << endl;
    }
    
    return 0;
}
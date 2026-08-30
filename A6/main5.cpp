#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    
    cout << "Введите размер координатной оси: ";
    cin >> size;
    
    cout << string(size, ' ') << "^\n";
    
    for (int i = 0; i < size - 1; i++)
    {
        cout << string(size, ' ') << "|\n";
    }
    
    cout << string(size, '-') << "+" << string(size, '-') << ">\n";
 
    for (int i = 0; i < size; i++)
    {
        cout << string(size, ' ') << "|\n";
    }
    
    return 0;
}
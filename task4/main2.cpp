#include <iostream>

using namespace std;

int main()
{
    int day;

    cout << "Введите число: ";
    cin >> day;
    
    if (( day < 1 ) || ( day > 31 ))
    {
        cout << "Некорректная дата" << endl;
        return 1;
    }
    
    int dayOfWeek = (day - 1) % 7 + 1; // 1 - понедельник, 7 - воскресенье
    
    if ((day >= 1 && day <= 5) || (day >= 8 && day <= 10))
    {
        cout << "выходной" << endl;
    }
    else if ( dayOfWeek == 6 || dayOfWeek == 7)
    {
        
    }
    else
    {
        cout << "рабочий" << endl;
    }
        

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int totalLength, exclamationCount;
    
    cout << "Введите общую длину колонтитула: ";
    cin >> totalLength;
    
    cout << "Введите количество восхищательных знаков: ";
    cin >> exclamationCount;
    
    if (exclamationCount > totalLength)
     {
        cout << "Ошибка: количество знаков не может превышать общую длину!" << endl;
        return 1;
    }
    
    int spacesBefore = (totalLength - exclamationCount) / 2;
    int spacesAfter = totalLength - exclamationCount - spacesBefore;
    
    cout << string(totalLength, '-') << endl;
    cout << string(spacesBefore, ' ') 
              << string(exclamationCount, '!') 
              << string(spacesAfter, ' ') << endl;
    cout << string(totalLength, '-') << endl;
    
    return 0;
}
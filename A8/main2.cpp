#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool IsValidNumber(const string& inputLine)
{
    if (inputLine.empty())
    {
        return false;
    }

    int index = 0;
    int len = inputLine.length();
    
    // Проверяем знак минус в начале
    if (inputLine[0] == '-')
    {
        if (len == 1)
        {
            return false; // Только минус - не число
        }
        index = 1;
    }
    
    bool hasDigit = false;
    bool dotFound = false;
    
    // Проверяем оставшиеся символы
    for (; index < len; index++)
    {
        if (isdigit(inputLine[index]))
        {
            hasDigit = true;
        }
        else if (inputLine[index] == '.')
        {
            if (dotFound)
            {
                return false; // Больше одной точки
            }
            dotFound = true;
        }
        else
        {
            return false; // Недопустимый символ
        }
    }
    
    // Должна быть хотя бы одна цифра
    return hasDigit;
}

int main()
{
    string inputLine;
    cout << "Введите длинное вещественное число: ";
    getline(cin, inputLine);
    
    if (IsValidNumber(inputLine))
    {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
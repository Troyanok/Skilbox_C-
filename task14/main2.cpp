#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string intPart, fracPart;
    
    cout << "Введите целую часть: ";
    cin >> intPart;
    cout << "Введите дробную часть: ";
    cin >> fracPart;

    string combined = intPart + "." + fracPart;
    double number = stod(combined);

    cout << "Результат: " << number << endl;
    return 0;
}
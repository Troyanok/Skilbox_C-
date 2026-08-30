#include <iostream>
#include <string>
#include <vector>

using namespace std;

string IntToRoman(int num)
{
    if (num < 1 || num > 3999)
    {
        return "Недопустимое число! Допустимый диапазон: 1-3999";
    }
    
    // Таблицы соответствия
    vector<string> thousands = {"", "M", "MM", "MMM"};
    vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    // Разбиваем число на разряды
    int th = num / 1000;
    int h = (num % 1000) / 100;
    int t = (num % 100) / 10;
    int o = num % 10;
    
    // Собираем римское число
    return thousands[th] + hundreds[h] + tens[t] + ones[o];
}

int main()
{
    int num;
    cout << "Введите число (1-3999): ";
    cin >> num;
    
    string roman = IntToRoman(num);
    cout << roman << endl;
    
    return 0;
}
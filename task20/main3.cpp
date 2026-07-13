#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagrams(const string& s1, const string& s2)
{
    if (s1.length() != s2.length()) 
    {
        return false;
    }

    map<char, int> freq;
    for (char c : s1)
    {
        ++freq[c];
    }
    for (char c : s2)
    {
        --freq[c];
    }

    for (const auto& pair : freq)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a;
    string b;

    cout << "Введите первую строку для проверки: ";
    cin >> a;
    cin.ignore();

    cout << "Введите вторую строку для проверки: ";
    cin >> b;
    cin.ignore();

    cout << "Проверка анаграммы: " << boolalpha << CheckAnagrams(a, b) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    cout << "Подсчёт слов в строке. Введите входную строку: ";
    string inputLine;
    getline(cin, inputLine);
    
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : inputLine)
    {
        if (c != ' ')
        {
            if (!inWord)
            {
                wordCount++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }
    
    cout << wordCount << endl;
    
    return 0;
}
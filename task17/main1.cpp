#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string subStr;
    cout << "Введите подстроку для поиска: ";
    cin >> subStr;

    fstream file("words.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return -1;
    }

    string content;
    int count = 0;

    while(file >> content)
    {
        if (content == subStr)
        {
            count ++;
        }
    }

    file.close();

    cout << "Число вхождений подстроки " << subStr << " : " << count << endl;

    return 0;
}

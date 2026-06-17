#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string filePath;
    cout << "Введите путь к файлу: ";
    cin >> filePath;

    fstream file(filePath);
    if (!file.is_open())
    {
        cout << "Failed to open file: " << filePath << endl;
        return -1;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}

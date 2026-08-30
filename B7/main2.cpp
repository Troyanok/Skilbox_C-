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

    const size_t bufferSize = 4096;
    char buffer[bufferSize];

    while (file.read(buffer, bufferSize))
    {
        cout.write(buffer, bufferSize);
    }

    streamsize bytesRead = file.gcount();
    if (bytesRead > 0)
    {
        cout.write(buffer, bytesRead);
    }

    file.close();
    cout << endl;

    return 0;
}

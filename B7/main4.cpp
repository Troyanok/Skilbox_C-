#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string picturePath;
    cout << "Введите путь к картинке: ";
    cin >> picturePath;

    ifstream pngFile(picturePath, ios::binary);
    if (!pngFile.is_open())
    {
        cout << "Failed to open file: " << picturePath << endl;
        return -1;
    }

    char buffer[4];
    pngFile.read(buffer, sizeof(buffer));
    
    if (pngFile.gcount() != sizeof(buffer))
    {
        cout << "Входной файл не является PNG (слишком короткий)" << endl;
        return 0;
    }

    bool isPNG = (static_cast<unsigned char>(buffer[0]) == 0x89) &&
                 (buffer[1] == 'P') &&
                 (buffer[2] == 'N') &&
                 (buffer[3] == 'G');

    if (isPNG)
    {
        cout << "Входной файл является PNG-изображением" << endl;
    }
    else
    {
        cout << "Входной файл не является PNG-изображением" << endl;
    }

    return 0;
}

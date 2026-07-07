#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int width, height;
    cout << "Введите ширину картины: ";
    cin >> width;
    cout << "Введите высоту картины: ";
    cin >> height;
    if ((width <= 0) || (height <= 0))
    {
        cout << "Размеры должны быть положительными.\n";
        return -1;
    }

    ofstream out("pic.txt");
    if (!out)
    {
        cout << "Не удалось создать файл pic.txt\n";
        return -1;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            out << (rand() % 2);
        }
        out << endl;
    }
    out.close();

    cout << "Бинарная картина сохранена в pic.txt" << endl;
    return 0;
}

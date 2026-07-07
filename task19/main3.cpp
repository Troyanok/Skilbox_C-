#include <iostream>
#include <cstdint> 
#include <fstream>
#include <vector>
#include <string>
#include <cmath>          // <cmath> вместо <math.h>

using namespace std;

struct Vector2D
{
    double x;
    double y;

    Vector2D(double inputX = 0, double inputY = 0)
        : x(inputX)
        , y(inputY)
    {};
};

Vector2D GetNewVector()
{
    cout << "Получение нового вектора" << endl;
    Vector2D vec;
    cout << "Введите координату x: ";
    cin >> vec.x;
    cout << "Введите координату y: ";
    cin >> vec.y;
    cout << "-----------" << endl;
    return vec;
}

double ComputeLength(const Vector2D& a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

Vector2D AddVectors()
{
    cout << "Сложение двух векторов" << endl;
    Vector2D a = GetNewVector();
    Vector2D b = GetNewVector();
    return Vector2D(a.x + b.x, a.y + b.y);
}

Vector2D SubVectors()
{
    cout << "Вычитание двух векторов" << endl;
    Vector2D a = GetNewVector();
    Vector2D b = GetNewVector();
    return Vector2D(a.x - b.x, a.y - b.y);
}

Vector2D ScaleVector()
{
    cout << "Умножение вектора на скаляр" << endl;
    Vector2D a = GetNewVector();
    double scalar;
    cout << "Скалярное значение: ";
    cin >> scalar;
    return Vector2D(a.x * scalar, a.y * scalar);
}

double LengthVector(const Vector2D& a)
{
    cout << "Длина вектора" << endl;
    return ComputeLength(a);
}

Vector2D NormalizeVector()
{
    cout << "Нормализация вектора" << endl;
    Vector2D a = GetNewVector();
    double len = ComputeLength(a);
    if (len == 0.0)
    {
        return Vector2D(0, 0);
    }
    return Vector2D(a.x / len, a.y / len);
}

void PrintVector2D(const Vector2D& vec)
{
    cout << "Значение вектора: " << endl;
    cout << "\tX: " << vec.x << endl;
    cout << "\tY: " << vec.y << endl;
    cout << endl;
}

void ProcCommand(const string& str)
{
    if (str == "add")
    {
        PrintVector2D(AddVectors());
    }
    else if (str == "subtract")
    {
        PrintVector2D(SubVectors());
    }
    else if (str == "scale")
    {
        PrintVector2D(ScaleVector());
    }
    else if (str == "length")
    {
        Vector2D a = GetNewVector();
        cout << "Длина вектора: " << LengthVector(a) << endl;
    }
    else if (str == "normalize")
    {
        PrintVector2D(NormalizeVector());
    }
    else
    {
        cout << "Введена неизвестная команда" << endl;
    }
}

int main()
{
    string command;
    while(1)
    {
        cout << "Введите команду: " << endl;
        cout << "\t add: Сложить два вектора" << endl;
        cout << "\t subtract: Вычесть из одного вектора другой" << endl;
        cout << "\t scale: Скалярно умножить число на вектор" << endl;
        cout << "\t length: Посчитать длину вектора" << endl;
        cout << "\t normalize: Нормализовать вектор" << endl;
        cout << "\t quit: Выход из программы" << endl;
        cin >> command;
        if (command == "quit")
        {
            break;
        }
        else
        {
            ProcCommand(command);
        }
        cout << "~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
    }
    return 0;
}

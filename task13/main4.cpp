#include <iostream>
using namespace std;

const int MATRIX_SIZE { 4 };

void InputMatrix(float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "Введите матрицу:" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
}

void InputVector(float vec[MATRIX_SIZE])
{
    cout << "Введите вектор:" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        cin >> vec[i];
    }
    cout << endl;
}

void PrintMatrix(const float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "Матрица: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintVector(const float vec[MATRIX_SIZE])
{
    cout << "Матрица: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}

void Multiplication(const float a[MATRIX_SIZE][MATRIX_SIZE],
                    const float b[MATRIX_SIZE],
                    float c[MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i ++)
    {
        float res { 0 };
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            res += a[i][j] * b[j];
        }
        c[i] = res;
    }
}

int main()
{
    cout << "Введите данные." << endl;
    float a[MATRIX_SIZE][MATRIX_SIZE];
    float b[MATRIX_SIZE];
    float c[MATRIX_SIZE] = {0, 0, 0, 0};

    cout << "Матрица: " << endl;
    InputMatrix(a);

    cout << "Вектор: " << endl;
    InputVector(b);
    
    PrintMatrix(a);
    PrintVector(b);

    Multiplication(a, b, c);
    cout << "Результат умножения: " << endl;
    PrintVector(c);
    return 0;
}

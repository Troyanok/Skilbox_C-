#include <iostream>
using namespace std;

const int MATRIX_SIZE { 4 };

void InputMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
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

bool IsEqualMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void ConvertToDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i != j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void PrintMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
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

int main()
{
    cout << "Введите матрицы." << endl;
    int a[MATRIX_SIZE][MATRIX_SIZE], b[MATRIX_SIZE][MATRIX_SIZE];

    cout << "1ая матрица: " << endl;
    InputMatrix(a);

    cout << "2ая матрица: " << endl;
    InputMatrix(b);

    PrintMatrix(a);
    PrintMatrix(b);
    
    if (!IsEqualMatrix(a, b))
    {
        cout << "Матрицы не равны!" << endl;
        return 0;
    }
    cout << "Матрицы равны!" << endl;

    ConvertToDiagonal(a);
    PrintMatrix(a);
    return 0;
}

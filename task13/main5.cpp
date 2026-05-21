#include <iostream>
using namespace std;

const int MATRIX_SIZE { 12 };

void InitialMatrix(bool matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = true;
        }
    }
}

void PrintMatrix(const bool matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "Вид пупырки: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i ++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << (matrix[i][j] ? 'o' : 'x') << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool IsEmptyMatrix(const bool matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void PopArea(bool matrix[MATRIX_SIZE][MATRIX_SIZE], int col1, int col2, int line1, int line2)
{
    if ((col1 < 0) || (col1 > MATRIX_SIZE) || (col2 < 0) || (col2 > MATRIX_SIZE) ||
        (line1 < 0) || (line1 > MATRIX_SIZE) || (line2 < 0) || (line2 > MATRIX_SIZE))
    {
        cout << "Пользователь ввёл ошибочные координаты!" << endl;
        return;
    }
    
    for (int i = col1; i < col2; i++)
    {
        for (int j = line1; j < line2; j++)
        {
            if (matrix[i][j])
            {
                cout << "Pop!" << endl;
                matrix[i][j] = false;
            }
        }
    }
    cout << endl;
}


int main()
{
    bool matrix[MATRIX_SIZE][MATRIX_SIZE];

    int col1, col2, line1, line2;

    InitialMatrix(matrix);

    cout << "Добро пожаловать в игру Пупырка! Лопайте прямоугольные области" << endl;
    cout << "Вводите координаты левого верхнего и правого нижнего угла" << endl;

    while(!IsEmptyMatrix(matrix))
    {
        PrintMatrix(matrix);
        cout << "Введите координаты: " << endl;
        cin >> col1 >> line1 >> col2 >> line2;
        
        PopArea(matrix, min(col1, col2), max(col1, col2), min(line1, line2), max(line1, line2));
        if (IsEmptyMatrix(matrix))
        {
            cout << "Все пузырьки лопнуты!" << endl;
            PrintMatrix(matrix);
        }
    }

    return 0;
}

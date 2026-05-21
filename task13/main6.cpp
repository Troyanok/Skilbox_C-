#include <iostream>
using namespace std;

const int MATRIX_SIZE { 5 };

void InitialSnakeMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int value { 0 };
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        int changePos = 1 - 2 * (i % 2);
        int startPos = (MATRIX_SIZE - 1) * (i % 2);
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            int col = startPos + j * changePos;
            matrix[i][col] = value++;
        }
    }
}

void PrintMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    InitialSnakeMatrix(matrix);
    PrintMatrix(matrix);
    
    return 0;
}

#include <iostream>
using namespace std;

const int columns { 3 };
const int lines { 3 };

char gameField[columns][lines] {{'-', '-', '-'},
                                {'-', '-', '-'},
                                {'-', '-', '-'}};
void PrintGameField()
{
    cout << "Game Field" << endl;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << gameField[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool CheckInputArgs(int row, int col)
{
    return (row >= 0 && row < lines && col >= 0 && col < columns && gameField[row][col] == '-');
}

char CheckField()
{
    // Горизонтали
    for (int i = 0; i < lines; i++)
    {
        if (gameField[i][0] != '-' && gameField[i][0] == gameField[i][1] && gameField[i][1] == gameField[i][2])
        {
            return gameField[i][0];
        }
    }

    // Вертикали
    for (int j = 0; j < columns; j++)
    {
        if (gameField[0][j] != '-' && gameField[0][j] == gameField[1][j] && gameField[1][j] == gameField[2][j])
        {
            return gameField[0][j];
        }
    }

    // Ничья
    bool isFull = true;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (gameField[i][j] == '-')
            {
                isFull = false;
            }
        }
    }
    return isFull ? 'D' : ' ';
}

int main()
{
    cout << "Begin of game!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    PrintGameField();

    char currentPlayer = 'X';
    int row, col;
    char result = ' ';

    while (1)
    {
        cout << "Введите координаты для игрока " << (currentPlayer == 'X' ? "1 (X)" : "2 (O)") << endl;
        cout << "Номер строки (0..2): ";
        cin >> row;
        cout << "Номер столбца (0..2): ";
        cin >> col;
        cout << endl;

        if (!CheckInputArgs(row, col))
        {
            cout << "Неверные координаты или клетка занята. Попробуйте заново!" << endl;
        }
        else
        {
            gameField[row][col] = currentPlayer;
            result = CheckField();

            if (result == 'D')
            {
                cout << "Ничья!" << endl;
                break;
            }
            else if (result != ' ')
            {
                cout << "Победил игрок " << (currentPlayer == 'X' ? "1" : "2") << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        PrintGameField();
    }
    
    PrintGameField();
    return 0;
}

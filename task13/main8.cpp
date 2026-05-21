#include <iostream>
using namespace std;

const int MATRIX_SIZE { 10 };

const int SHIP_SIZE_MATRIX[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
const int SHIP_COUNT {sizeof(SHIP_SIZE_MATRIX) / sizeof(SHIP_SIZE_MATRIX[0])};

void ClearField(bool field[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            field[i][j] = false;
        }
    }
}

void PrintField(const bool field[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "\t\t";
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        cout << i << "\t\t";
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << (field[i][j] ? "# " : ". ");
        }
        cout << endl;
    }
}

bool CanPlaceShip(const bool field[MATRIX_SIZE][MATRIX_SIZE],
                  int col1, int line1, int col2, int line2)
{
    if ((col1 < 0)  || (col1 > MATRIX_SIZE)  || (col2 < 0)  || (col2 > MATRIX_SIZE) ||
        (line1 < 0) || (line1 > MATRIX_SIZE) || (line2 < 0) || (line2 > MATRIX_SIZE))
    {
        return false;
    }

    if ((col1 != col2) && (line1 != line2))
    {
        return false;
    }

    int diffCol = (col1 < col2) ? 1 : (line1 > line2 ? -1 : 0);
    int diffLine = (line1 < line2) ? 1 : (col1 > col2 ? -1 : 0);
    int col { col1 }, line { line1 };
    while(1)
    {
        if (field[col][line])
        {
            return false;
        }
        if ((col == col2) && (line == line2))
        {
            break;
        }
        col += diffCol;
        line += diffLine;
    }
    return true;
}

void PlaceShip(bool field[MATRIX_SIZE][MATRIX_SIZE],
               int col1, int line1, int col2, int line2)
{
    int diffCol = (col1 < col2) ? 1 : (line1 > line2 ? -1 : 0);
    int diffLine = (line1 < line2) ? 1 : (col1 > col2 ? -1 : 0);
    int col { col1 }, line { line1 };
    while(1)
    {
        field[col][line] = true;if ((col == col2) && (line == line2))
        {
            break;
        }
        col += diffCol;
        line += diffLine;
    }
}

void PlaceAllShips(bool field[MATRIX_SIZE][MATRIX_SIZE], int playerNum)
{
    cout << "Игрок " << playerNum << ". расставьте свои корабли" << endl;
    int col1, col2, line1, line2;
    for (int i = 0; i < SHIP_COUNT; i++)
    {
        int size = SHIP_SIZE_MATRIX[i];
        cout << "Разместите " << (size == 1 ? "однопалубный"
                                  : size == 2 ? "двухпалубный" 
                                  : size == 3 ? "трёхпалубный"
                                  : "четырёхпалубный") 
                              << "корабль (длина и конец)" << endl;
        while(1)
        {
            cout << "Введите координаты начала и конца: ";
            cin >> col1 >> line1 >> col2 >> line2;
            int length;
            if (col1 == col2)
            {
                length = abs(line1 - line2) + 1;
            }
            else if (line1 == line2)
            {
                length = abs(col1 - col2) + 1;
            }
            else
            {
                cout << "Корабль должен быть строго горизонтальным или вертикальным!" << endl;
                continue;
            }

            if (length != size)
            {
                cout << "Длина корабля неверная" << endl;
                continue;
            }
            if (!CanPlaceShip(field, col1, line1, col2, line2))
            {
                cout << "Невозможно разместить корабль!" << endl;
                continue;
            }

            PlaceShip(field, col1, line1, col2, line2);
            PrintField(field);
            break;
        }
    } 
}

bool HasShip(const bool field[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (field[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

bool Shoot(bool field[MATRIX_SIZE][MATRIX_SIZE], int col, int line)
{
    if ((col < 0) || (col >= MATRIX_SIZE) || 
        (line < 0) || (line >= MATRIX_SIZE))
    {
        cout << "Координаты введены неверно!" << endl;
        return false;
    }
    if (field[col][line])
    {
        field[col][line] = false;
        cout << "Попадание!" << endl;
        return true;
    }
    cout << "Промах!" << endl;
    return false;
}

void PlayGame(bool field1[MATRIX_SIZE][MATRIX_SIZE], bool field2[MATRIX_SIZE][MATRIX_SIZE])
{
    int currentPlayer { 1 };
    bool (*currentField)[MATRIX_SIZE] = field2;
    int opponent { 2 };
    int col, line;
    bool hit { false };
    while (HasShip(field1) && HasShip(field2))
    {
        cout << "Ход игрока: " << currentPlayer << ". Поле противника " << endl;
        PrintField(currentField);

        cout << "Введите координаты выстрела: ";
        cin >> col >> line;
        hit = Shoot(currentField, col, line);

        if (hit && !HasShip(currentField))
        {
            cout << "Игрок " << currentPlayer << " уничтожил все коробли и выиграл. " << endl;
            break;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        currentField = (currentPlayer == 1) ? field2 : field1;
    }
}

int main()
{
    bool field1[MATRIX_SIZE][MATRIX_SIZE];
    bool field2[MATRIX_SIZE][MATRIX_SIZE];

    ClearField(field1);
    ClearField(field2);
    
    cout << "===== Морской бой ====" << endl;
    PlaceAllShips(field1, 1);
    PlaceAllShips(field2, 2);

    PlayGame(field1, field2);
    return 0;
}

#include <iostream>
using namespace std;

const int LAND_SIZE { 5 };
const int MAX_HEIGHT { 10 };

void InputHeight(int heights[LAND_SIZE][LAND_SIZE])
{
    cout << "Введите высоты блоков (0 - 10) для каждого сектора " << LAND_SIZE << " x " << LAND_SIZE << endl;
    for (int i = 0; i < LAND_SIZE; i++)
    {
        for (int j = 0; j < LAND_SIZE; j++)
        {
            while(1)
            {
                cout << "Сектор [" << i << "][" << j << "]: ";
                cin >> heights[i][j];
                if ((heights[i][j] >= 0) && (heights[i][j] <= MAX_HEIGHT))
                {
                    break;
                }
                cout << "ОШибка, введите другое значение!" << endl;
            }
        }
    }
}

void BuildWorld(const int heights[LAND_SIZE][LAND_SIZE],
                bool world[LAND_SIZE][LAND_SIZE][MAX_HEIGHT])
{
    for (int i = 0; i < LAND_SIZE; i++)
    {
        for (int j = 0; j < LAND_SIZE; j++)
        {
            for (int k = 0; k < MAX_HEIGHT; k++)
            {
                world[i][j][k] = (k < heights[i][j]);
            }
        }
    }
}

void PrintSlice(const bool world[LAND_SIZE][LAND_SIZE][MAX_HEIGHT],
                int level)
{
    cout << "Горизонтальный срез на уровне " << level << endl;

    for (int i = 0; i < LAND_SIZE; i++)
    {
        for (int j = 0; j < LAND_SIZE; j++)
        {
            cout << (world[i][j][level] ? 1 : 0) << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int heights[LAND_SIZE][LAND_SIZE];
    bool world[LAND_SIZE][LAND_SIZE][MAX_HEIGHT];
    int level;

    InputHeight(heights);
    BuildWorld(heights, world);

    while(1)
    {
        cout << "Введите уровень среза (или -1, чтобы закончить работу): ";
        cin >> level;
        
        if (level == -1)
        {
            break;
        }
        if ((level < 0) || (level > MAX_HEIGHT))
        {
            cout << "Ввели недопустимое значение уровня" << endl;
        }
        else
        {
            PrintSlice(world, level);
        }
    }
    return 0;
}

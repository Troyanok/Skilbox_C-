#include <iostream>

using namespace std;

int main()
{
    int min_speed {750}, max_speed {850};
    int min_height {9000}, max_height {9500};
    int speed, height;
    bool check_speed {0}, check_height {0};

    cout << "Введите скорость самолёта: ";
    cin >> speed;

    cout << "Введите высоту подъёма самолёта над уровнем моря: ";
    cin >> height;

    check_speed = (speed > min_speed) && (speed < max_speed);
    check_height = (height > min_height) && (height < max_height);
    if ((check_speed) && (check_height))
    {
        cout << "Входные параметры соответствуют требованиям!" << endl;
    }
    else if (!check_speed)
    {
        cout << "Введённая скорость " << speed << " не соответствует допустимому диапазону значений!" << endl;
        return -1;
    }
    else if (!check_height)
    {
        cout << "Введённая высота " << height << " не соответствует допустимому диапазону значений!" << endl;
        return -1;
    }

    return 0;
}
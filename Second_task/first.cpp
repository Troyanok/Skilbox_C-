#include <iostream>
#include <string>

using namespace std;

int main()
{
    int countPassenger      = 0;
    int tiketPrice          = 20;
    int income              = 0;
    int countExitPassenger;
    int countComePassenger;
    string nameStation;

    for (int i = 0; i < 4; i++)
    {
        countExitPassenger = 0;
        countComePassenger = 0;
        nameStation = "";

        cout << "Прибываем на остановку: ";
        cin >> nameStation;

        cout << "В салоне пассажиров: " << countPassenger << endl;
    
        cout << "Сколько пассажиров вышло на остановке? ";
        cin >> countExitPassenger;
    
        cout << "Сколько пассажиров зашло на остановке? ";
        cin >> countComePassenger;

        countPassenger = countPassenger - countExitPassenger + countComePassenger;
    
        cout << "Отправляемся с остановки << " << nameStation << " >>. В салоне пассажиров: " << countPassenger << endl;

        cout << "-----------Едем---------" << endl;
        income += countComePassenger * tiketPrice;
    }

    cout << "Всего заработали: " << income << " руб." << endl;
    cout << "Зарплата водителя: " << income * 0.25 << " руб." << endl;
    cout << "Расходы на топливо: " << income * 0.2 << " руб." << endl;
    cout << "Налоги: " << income * 0.2 << " руб." << endl;
    cout << "Расходы на ремонт машины: " << income * 0.2 << " руб." << endl;
    cout << "Итого доход: "<< income * (1 - 0.25 - 0.2*3) << endl;

    return 0;
}

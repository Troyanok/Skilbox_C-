#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    string command;

    while (true)
    {
        cout << "Команды для таймера обратного отсчёта:" << endl;
        cout << "\t start ММ:СС - Запустить таймер;" << endl;
        cout << "\t exit - Завершить работу программы." << endl;

        cin >> command;
        cin.ignore();

        if (command == "exit")
        {
            break;
        }
        else if (command == "start")
        {
            int mins, secs;
            char colon;
            cin >> mins >> colon >> secs;

            if (cin.fail() || colon != ':' || mins < 0 || secs < 0 || secs > 59)
            {
                cout << "Неверный формат. Используйте ММ:СС." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            int total = mins * 60 + secs;
            if (total <= 0)
            {
                cout << "Время должно быть положительным." << endl;
                continue;
            }

            time_t start_time = time(nullptr);
            time_t target = start_time + total;
            time_t last_printed = 0;

            cout << "Таймер запущен." << endl;
            while (true)
            {
                time_t now = time(nullptr);
                if (now >= target)
                {
                    break;
                }
                if (now != last_printed)
                {
                    int remaining = static_cast<int>(difftime(target, now));
                    int m = remaining / 60;
                    int s = remaining % 60;
                    cout << "\r" << setfill('0') << setw(2) << m
                         << ":" << setw(2) << s << flush;
                    last_printed = now;
                }
            }
            cout << "\rДЗЫНЬ! ДЗЫНЬ! ДЗЫНЬ! " << endl;
        }
        else
        {
            cout << "Неизвестная команда." << endl;
        }
        cout << endl;
    }
    return 0;
}

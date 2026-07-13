#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

struct Friend
{
    string name;
    time_t birthday;   

    Friend()
        : name("")
        , birthday(0)
    {};

    void set(const string& n, int year, int month, int day)
    {
        name = n;
        tm t = {};
        t.tm_year = 100;          
        t.tm_mon  = month - 1;
        t.tm_mday = day;
        t.tm_hour = 0;
        t.tm_min  = 0;
        t.tm_sec  = 0;
        t.tm_isdst = -1;
        birthday = mktime(&t);
    };
};

int main()
{
    vector<Friend> friends;
    string command;

    while (true)
    {
        cout << "Команды для работы с днями рождения:" << endl;
        cout << "\t add - add друга и дату рождения;" << endl;
        cout << "\t near - Показать near дни рождения;" << endl;
        cout << "\t list - Вывести весь list;" << endl;
        cout << "\t exit - Завершить работу программы." << endl;

        cin >> command;
        cin.ignore();

        if (command == "exit")
        {
            break;
        }
        else if (command == "add")
        {
            string name;
            int year, month, day;
            char d1, d2;

            cout << "Имя: ";
            cin >> name;
            cout << "Дата рождения (ГГГГ/ММ/ДД): ";
            cin >> year >> d1 >> month >> d2 >> day;

            if (d1 != '/' || d2 != '/' || month < 1 || month > 12 || day < 1 || day > 31)
            {
                cout << "Неверный формат." << endl;
                continue;
            }

            Friend fr;
            fr.set(name, year, month, day);
            friends.push_back(fr);
            cout << "Добавлен: " << name << "." << endl;
        }
        else if (command == "near")
        {
            if (friends.empty())
            {
                cout << "list друзей пуст." << endl;
                continue;
            }

            time_t now = time(nullptr);
            tm* now_tm = localtime(&now);
            int today_yday = now_tm->tm_yday;

            const int DAYS_IN_YEAR = 366;
            int min_wait = DAYS_IN_YEAR + 1;

            for (const auto& fr : friends)
            {
                tm bday_tm = *localtime(&fr.birthday);
                bday_tm.tm_year = now_tm->tm_year;
                bday_tm.tm_isdst = -1;
                mktime(&bday_tm);
                int bday_yday = bday_tm.tm_yday;
                int wait = (bday_yday - today_yday + DAYS_IN_YEAR) % DAYS_IN_YEAR;
                if (wait < min_wait)
                {
                    min_wait = wait;
                }
            }

            cout << endl;
            if (min_wait == 0)
            {
                cout << "=== СЕГОДНЯ ДНИ РОЖДЕНИЯ ===" << endl;
                for (const auto& fr : friends)
                {
                    tm bday_tm = *localtime(&fr.birthday);
                    bday_tm.tm_year = now_tm->tm_year;
                    bday_tm.tm_isdst = -1;
                    mktime(&bday_tm);
                    if (bday_tm.tm_yday == today_yday)
                    {
                        cout << fr.name << " - "
                             << setfill('0') << setw(2) << bday_tm.tm_mon+1
                             << "/" << setw(2) << bday_tm.tm_mday << endl;
                    }
                }
            }
            else
            {
                cout << "near дни рождения через " << min_wait << " дн.:" << endl;
                for (const auto& fr : friends)
                {
                    tm bday_tm = *localtime(&fr.birthday);
                    bday_tm.tm_year = now_tm->tm_year;
                    bday_tm.tm_isdst = -1;
                    mktime(&bday_tm);
                    int wait = (bday_tm.tm_yday - today_yday + DAYS_IN_YEAR) % DAYS_IN_YEAR;
                    if (wait == min_wait)
                    {
                        cout << fr.name << " - "
                             << setfill('0') << setw(2) << bday_tm.tm_mon+1
                             << "/" << setw(2) << bday_tm.tm_mday << endl;
                    }
                }
            }
        }
        else if (command == "list")
        {
            if (friends.empty())
            {
                cout << "list друзей пуст." << endl;
                continue;
            }
            for (const auto& fr : friends)
            {
                tm* bd = localtime(&fr.birthday);
                cout << fr.name << " - "
                     << setfill('0') << setw(2) << bd->tm_mon+1
                     << "/" << setw(2) << bd->tm_mday << endl;
            }
        }
        else
        {
            cout << "Неизвестная команда." << endl;
        }
        cout << endl;
    }
    
    return 0;
}

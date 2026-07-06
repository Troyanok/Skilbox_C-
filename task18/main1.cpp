#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int DaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeapYear(const int year)
{
    return (year % 4 == 0);
}

bool IsValidDate(const string& date)
{
    if (date.length() != 10)
    {
        return false;
    }

    if ((date[2] != '.') || (date[5] != '.'))
    {
        return false;
    }

    try
    {
        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6, 4));

        if ((month < 1) || (month > 12))
        {
            return false;
        }

        if (year < 1)
        {
            return false;
        }

        DaysInMonth[1] = IsLeapYear(year) ? 29 : 28;

        if ((day < 1) || (day > DaysInMonth[month - 1]))
        {
            return false;
        }
        return true;
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
        return false;
    }
    
}

int main()
{
    string firstName, lastName, date;
    double amount;

    cout << "Введите имя получателя: ";
    cin >> firstName;
    cout << "Введите фамилию получателя: ";
    cin >> lastName;
    cout << "Введите дату выдачи (ДД.ММ.ГГГГ): ";
    cin >> date;
    while (!IsValidDate(date))
    {
        cout << "Неверный формат или несуществующая дата. Повторите: ";
        cin >> date;
    }
   
    cout << "Введите сумму выплаты (руб.): ";
    cin >> amount;
    while (amount <= 0)
    {
        cout << "Сумма должна быть положительной. Повторите: ";
        cin >> amount;
    }

    ofstream outFile("payroll.txt", std::ios::app);
    if (!outFile.is_open())
    {
        cerr << "Не удалось открыть файл для записи." << endl;
        return -1;
    }

    outFile << firstName << " " << lastName << " " << date << " " << amount << endl;
    outFile.close();
    cout << "Запись успешно добавлена в ведомость." << endl;
    
    return 0;
}

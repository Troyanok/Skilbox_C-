#include <iostream>
#include <array>
#include <string>

using namespace std;


const int countWeekDay {7};
const int countMonth {12};

std::array<int, countMonth> monthCountDay = 
{
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
};

        
int main()
{
        int yearInfo, numMonth, beginMonth, numDay;


        cout << "Укажите информацию о текущем годе: високосный он или нет (0 - нет, 1 - да) ";
        cin >> yearInfo;


        cout << "Введите номер месяца (от 1 до 12): ";
        cin >> numMonth;

        cout << "Введите день, с которого начинается месяц (от 1 до 7): ";
        cin >> beginMonth;

        cout << "Введите число текущего месяца: ";
        cin >> numDay;


        if ((yearInfo > 1) || (yearInfo < 0))
        {
                cout << "Информация о том, какой год сейчас, была предоставлена неверно!" << endl;
                return -1;
        }

        if (yearInfo == 1)
        {
                monthCountDay[1] = 29;
        }


        if ((numMonth > countMonth) || (numMonth < 0))
        {
                cout << "Введённого пользователем месяца не существует!"<< endl;
        return -1;
        }

        if ((beginMonth > countWeekDay) || (beginMonth < 0))
        {
                cout << "Неправильное начало месяца!" << endl;
                return -1;
        }

        int countDay = monthCountDay[numMonth - 1];

        if ((numDay > countDay) || (numDay < 0))
        {
                cout << "День месяца был введён неверно!" << endl;
        }

        int checkDay = ((beginMonth - 1) + (numDay - 1)) % 7;
	cout << checkDay << endl;

	if ((checkDay == 5) || (checkDay == 6))
        {
                cout << "Выходной, ура!" << endl;
        }
        else
        {
                cout << "Работаем ... "<< endl;
        }


        return 0;
}


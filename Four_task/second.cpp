#include <iostream>

using namespace std;

int main()
{
	int numDay;

	cout << "Введите число: ";
	cin >> numDay;

	if ((numDay < 0) || (numDay > 31))
	{
		cout << "День месяца был введён неверно!" << endl;
		return -1;
	}

	int dayWeek = (numDay - 1) % 7;
	bool checkWeekend = ((dayWeek == 5) || (dayWeek == 6));

	if (((numDay >= 1) && (numDay <= 5)) || ((numDay >= 8) && (numDay <= 10)) || checkWeekend)
	{
		cout << "Выходной, ура!" << endl;
	}
	else
	{
		cout << "Работаем ... " << endl;
	}

	return 0;
}


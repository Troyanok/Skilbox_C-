#include <iostream>

using namespace std;

int main()
{
	int currentYear, currentMonth, currentDay;
	cout << "Введите текущую дату (день месяц год): ";
	cin >> currentDay >> currentMonth >> currentYear;
    
	int birthDay, birthMonth, birthYear;
	cout << "Введите дату рождения (день месяц год): ";
	cin >> birthDay >> birthMonth >> birthYear;


	int age = currentYear - birthYear;


	if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
	{
		age--;
	}


	if (age > 18)
	{
		cout << "Можно продать алкоголь." << endl;
	}
	else if (age == 18)
	{
		if (currentMonth > birthMonth || (currentMonth == birthMonth && currentDay > birthDay))
		{
			cout << "Можно продать алкоголь." << endl;
		}
		else
		{
			cout << "Нельзя продать алкоголь!" << endl;
		return -1;
		}
	}
	else
	{
		cout << "Нельзя продать алкоголь!" << endl;
		return -1;
	}
	return 0;
}

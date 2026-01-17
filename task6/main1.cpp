#include <iostream>

using namespace std;

int main()
{
	const int allSource = 100;
	int currentMonth = 0;
	const int countSource = 4;
	
	cout << "Всего гречки было на начало подсчёта: " << allSource << endl;
	
	for (int i = allSource - countSource; i >= 0; i -= countSource)
	{
		currentMonth++;
		cout << "После " << currentMonth << " месяца у вас в запасе останется " << i << "кг гречки" << endl;
	}
	cout << "После " << currentMonth << " месяца гречка закончится" << endl;
	return 0;
}
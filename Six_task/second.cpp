#include <iostream>

using namespace std;

int main()
{
	int countWater, countMilk, var;
	int countLatte = 0, countAmericano = 0;

	cout << "Введите количество воды в мл. : ";
	cin >> countWater;

	cout << "Введите количество  молока в мл. : ";
	cin >> countMilk;

	while (1)
	{
		if ((countWater < 300) && (!((countWater >= 30) && (countMilk >= 270))))
		{
			break;
		}
		cout << "Выберите напиток (1 - американо, 2 - латте): ";
		cin >> var;

		if (var == 1)
		{
			if (countWater >= 300)
			{
				cout << "Ваш напиток готов." << endl;
				countWater -= 300;
				countAmericano++;
			}
			else
			{
				cout << "Не хватает воды." << endl;
			}
		}
		else if (var == 2)
		{
			if ((countWater >= 30) && (countMilk >= 270))
			{
				cout << "Ваш напиток готов." << endl;
				countWater -= 30;
				countMilk -= 270;
				countLatte++;
			}
			else if (countWater < 30)
			{
				cout << "Не хватает воды." << endl;
			}
			else
			{
				cout << "Не хватает молока." << endl;
			}
		}

		cout << "***Отчёт***" << endl;
		cout << "Ингредиентов осталось: " << endl;
		cout << "\t Вода: " << countWater << endl;
		cout << "\t Молоко: " << countMilk << endl;
		cout << "Кружек американо приготовлено: " << countAmericano << endl;
		cout << "Кружек латте приготовлено: " << countLatte << endl;
	}

	return 0;

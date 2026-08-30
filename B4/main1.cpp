#include <iostream>
#include <string>

using namespace std;

int main()
{
	double speed = 0.0;
	double delta;
	char speedStr[20]; // буфер для форматированного вывода

	do
	{
		cout << "Speed delta: ";
		cin >> delta;

		speed += delta;

		// Ограничение скорости
		if (speed < 0.0)
		{
			speed = 0.0;
		}

		if (speed > 150.0)
		{
			speed = 150.0;
		}

		// Форматирование с одним знаком после запятой
		std::sprintf(speedStr, "%.1f", speed);
		cout << "Speed: " << speedStr << endl;

	} while (speed > 0.01); // остановка, когда скорость <= 0.01

	cout << "Автомобиль остановился." << endl;
	return 0;
}

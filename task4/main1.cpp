#include <iostream>

using namespace std;

int main()
{
	int speed, height;
	int min_speed {750}, max_speed {850};
	int min_height {9000}, max_height {9500};
	
	cout << "Введите текущую скорость самолёта: ";
	cin >> speed;
	cout << "Введите текущую высоту самолёта над уровнем моря: ";
	cin >> height;


	if ((speed < min_speed) || (speed > max_speed))
	{
		cout << "Введённая скорость не соответствует стандартам! Скорость должна быть от " << min_speed
		     << " до " << max_speed << " км/ч" << endl;
		return -1;
	}

	if ((height < min_height) || (height > max_height))
	{
		cout << "Введённая высота не соответствует стандартам! Высота должна быть от " << min_height
		     << " до " << max_height << " м" << endl;
		return -1;
	}

	cout << "Введённая скорость " << speed << "км/ч и высота " << height << " м соответствуют стандартам, продолжайте полёт!" << endl;

	return 0;
}

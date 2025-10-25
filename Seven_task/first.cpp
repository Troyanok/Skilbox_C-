#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float F, m, t;
	float a, S;
	
	cout << "Введите силу F (H)";
	cin >> F;
	
	cout << "Введите массу (кг)";
	cin >> m;
	
	cout << "Введите время (с)";
	cin >> t;
	
	if ((F < 0) || (m <= 0) || (t < 0))
	{
		cout << "Введённые данные некорректны!" << endl;
		return -1;
	}
	
	a = F / m;
	S = a * pow(t, 2) / 2;
	cout << "Пройденный путь составляет: " << S << "км." <<endl;
	
	return 0;
}
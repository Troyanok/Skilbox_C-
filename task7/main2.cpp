#include <iostream>

using namespace std;

int main()
{
	float health, resistance, damage, fullDamage;
	
	cout << "Введите показатель здоровья орка (0-1): ";
	cin >> health;
	
	cout << "Введите показатель сопрротивления к уроны (0-1): ";
	cin >> resistance;
	
	if ((health < 0) || (health > 1))
	{
		cout << "Введённый показатель здоровья вне допустимого диапазона" << endl;
		return -1;
	}
	
	if ((resistance < 0) || (resistance > 1))
	{ 
		cout << "Введённый показатель сопротивления вне допустимого диапазона" << endl;
		return -1;
	}
	
	cout << "----------------------------" << endl;
	
	while(health > 0)
	{
		cout << "Введите показатель входящего урона: ";
		cin >> damage;
		
		fullDamage = 0;
		
		if (damage > 0)
		{
			fullDamage = damage * resistance;
		}
		
		cout << "Урон " << damage << ", сопротивляемость " << resistance << ", по орку будет нанесено " << fullDamage << " урона." << endl;
		health -= fullDamage;
	}
	
	cout << "----------------------------" << endl;
	cout << "Орк побеждён, ура!" << endl;
	return 0;
}
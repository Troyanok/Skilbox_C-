#include <iostream> 

using namespace std; 
 
const int column { 2 };
const int line { 6 };

/// @brief Массив столовых приборов
int tableAppliancePackage[column][line] {{4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3}};

/// @brief Массив тарелок
int platePackage[column][line] {{3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2}};

/// @brief Массив стульев
int chairPackage[column][line] {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

/// @brief Вывести текущую информацию о гостях
void PrintBanquetInfo()
{
	int guestNum { 0 };
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < line; j++)
		{
			guestNum++;
			cout << ((j == 0) ? "Vip guest" : "Base guest") << endl;
			cout << "Info about guest " << guestNum << endl;
			cout << "Appliance count: " << tableAppliancePackage[i][j] << 
			" \t Plate count: " << platePackage[i][j] <<
			" \t Chair count: " << chairPackage[i][j] << endl;
			cout << "----------------" << endl;
		}
	}
	cout << endl;
}

int main() 
{ 
	cout << "Begin of Banquet table" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	PrintBanquetInfo();
	
	cout << "First cituation: add chair for [0, 4] guest" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	chairPackage[0][4] += 1;
	PrintBanquetInfo();
	
	cout << "Second cituation: del 1 plate for [1, 2] guest" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	tableAppliancePackage[1][2] -= 1;
	PrintBanquetInfo();
	
	cout << "Third cituation: del 1 plate from Vip guest [0, 0] for [1, 2] guest" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	tableAppliancePackage[0][0] -= 1;
	tableAppliancePackage[1][2] += 1;
	PrintBanquetInfo();
	
	cout << "Fourth cituation: del 1 plate for Vip guest [0, 0]" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	platePackage[0][0] -= 1;
	PrintBanquetInfo();
    
    return 0; 
}

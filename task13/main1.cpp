#include <iostream> 

using namespace std; 
 
const int COLUMNS_SIZE { 2 };
const int LINES_SIZE { 6 };

/// @brief Массив столовых приборов
int tableAppliancePackage[COLUMNS_SIZE][LINES_SIZE] {{4, 4, 3, 3, 3, 3}, 
											         {3, 3, 3, 3, 3, 3}};

/// @brief Массив тарелок
int platePackage[COLUMNS_SIZE][LINES_SIZE] {{3, 3, 2, 2, 2, 2}, 
							    			{2, 2, 2, 2, 2, 2}};

/// @brief Массив стульев
int chairPackage[COLUMNS_SIZE][LINES_SIZE] {{1, 1, 1, 1, 1, 1},
											{1, 1, 1, 1, 1, 1}};

/// @brief Вывести текущую информацию о гостях
void PrintBanquetInfo()
{
	int guestNum { 0 };
	for (int i = 0; i < COLUMNS_SIZE; i++)
	{
		for (int j = 0; j < LINES_SIZE; j++)
		{
			guestNum++;
			// VIP – первые два места первого ряда
			cout << ((i == 0 && (j == 0 || j == 1)) ? "Vip guest" : "Base guest") << endl;
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

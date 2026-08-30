#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int maxWidth = 15, maxHeight = 20;
	int currentWidth = 7, currentHeight = 10;
	
	const string infoProg = "[Программа]: Марсоход находится на позиции ";
	const string infoCommand = " введите команду: ";
	const string infoUser = "[Оператор]: ";
	
	while(1)
	{
		cout << infoProg << currentWidth << ", " << currentHeight << infoCommand << endl;
		cout << infoUser;
		string inputCommand;
		cin >> inputCommand;
		
		if ((inputCommand == "A") && (currentWidth > 0))
		{
			currentWidth--;
		}
		else if ((inputCommand == "W") && (currentHeight < maxHeight))
		{
			currentHeight++;
		}
		else if ((inputCommand == "S") && (currentHeight > 0))
		{
			currentHeight--;
		}
		else if ((inputCommand == "N") && (currentWidth < maxWidth))
		{
			currentWidth++;
		}
	}
	return 0;
}
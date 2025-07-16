#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, b, c, m, n, k;
	
	cout << "Введите размеры первой коробки (A B C): ";
	cin >> a >> b >> c;
	
	cout << "Введите размеры второй коробки (M N K): ";
	cin >> m >> n >> k;

	vector<int> firstBox = {a, b, c};
	vector<int> secondBox = {m, n, k};

	if  (((firstBox[0] < secondBox[0]) && (firstBox[1] < secondBox[1]) && (firstBox[2] < secondBox[2]))
	  || ((firstBox[0] < secondBox[0]) && (firstBox[1] < secondBox[2]) && (firstBox[2] < secondBox[1]))
	  || ((firstBox[0] < secondBox[1]) && (firstBox[1] < secondBox[0]) && (firstBox[2] < secondBox[2]))
	  || ((firstBox[0] < secondBox[1]) && (firstBox[1] < secondBox[2]) && (firstBox[2] < secondBox[0]))
	  || ((firstBox[0] < secondBox[2]) && (firstBox[1] < secondBox[0]) && (firstBox[2] < secondBox[1]))
	  || ((firstBox[0] < secondBox[2]) && (firstBox[1] < secondBox[1]) && (firstBox[2] < secondBox[0]))
	)
	{
		cout << "Первая коробка помещается во вторую!" << endl;
	}
	else if  (((secondBox[0] < firstBox[0]) && (secondBox[1] < firstBox[1]) && (secondBox[2] < firstBox[2]))
	       || ((secondBox[0] < firstBox[0]) && (secondBox[1] < firstBox[2]) && (secondBox[2] < firstBox[1]))
	       || ((secondBox[0] < firstBox[1]) && (secondBox[1] < firstBox[0]) && (secondBox[2] < firstBox[2]))
	       || ((secondBox[0] < firstBox[1]) && (secondBox[1] < firstBox[2]) && (secondBox[2] < firstBox[0]))
	       || ((secondBox[0] < firstBox[2]) && (secondBox[1] < firstBox[0]) && (secondBox[2] < firstBox[1]))
	       || ((secondBox[0] < firstBox[2]) && (secondBox[1] < firstBox[1]) && (secondBox[2] < firstBox[0]))
	)
	{
		cout << "Вторая коробка помещается в первую!" << endl;
	}
	else
	{
		cout << "Ошибка! Коробки не могут быть вложены друг в друга!" << endl;
		return -1;
	}

	return 0;
}

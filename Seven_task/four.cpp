#include <iostream>

using namespace std;

int main()
{
    int timer = 0;
    float fileSize, speed, installing;
    
    cout << "Укажите размер файла для скачивания: ";
    cin >> fileSize;
    
    cout << "Какова скорость вашего соединения? ";
    cin >> speed;
    
    if (fileSize < 0)
    {
    	cout << "Размер файла указан неверно!" << endl;
    	return -1;
    }
    
    installing = 0;
    
    while (installing < fileSize)
    {
    	installing += speed;
    	int value = (installing / fileSize)*100;
    	if (value > 100)
    	{
    		value = 100;
    		installing = fileSize;
    	}
    	cout << "Прошло " << ++timer << " сек. Скачано " << installing << " из " << fileSize << "МБ (" << value << "%)" << endl;
    }
    
    return 0;
}
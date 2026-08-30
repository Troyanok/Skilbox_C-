#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x, y, z;
    
    cout << "Введите размеры бруска:" << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;
   
    if ((x < 5) &&  (y < 5) && (z < 5))
    {
        cout << "Ошибка: минимальный размер бруска 5x5x5 см!" << endl;
        return -1;
    }
    
    int cubesX = x / 5;
    int cubesY = y / 5;
    int cubesZ = z / 5;
    
    int totalCubes = cubesX * cubesY * cubesZ;
    
    cout << "Из этого бруска можно изготовить " << totalCubes << " кубиков." << endl;
    
    int maxSet = 0;
    for (int n = 2; pow(n, 3) <= totalCubes; n++)
    {
        maxSet = pow(n, 3);
    }
    
    if (maxSet >= 8)
    {
        cout << "Из них можно составить набор из " << maxSet << " кубиков." << endl;
    }
    else
    {
       cout << "Из них нельзя составить набор для продажи (требуется минимум 8 кубиков)." << endl;
    }
    
    return 0;
}
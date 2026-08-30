#include <iostream>

using namespace std;

int main()
{
    int bacteria, antibioticDrops;
    
    cout << "Введите количество бактерий: ";
    cin >> bacteria;
    
    cout << "Введите количество антибиотика: ";
    cin >> antibioticDrops;
    
    if ((bacteria <= 0) || (antibioticDrops < 0))
    {
        cout << "Ошибка: введены некорректные данные!" << endl;
        return 1;
    }
    
    int hour = 1;
    int currentBacteria = bacteria;
    int antibioticEffect = 10; 
    
    while ((currentBacteria > 0) && (antibioticDrops > 0) && (antibioticEffect > 0))
    {
        currentBacteria *= 2;
        
        int killed = antibioticDrops * antibioticEffect;
        currentBacteria -= killed;
        
        if (currentBacteria < 0)
        {
            currentBacteria = 0;
        }
        
        cout << "После " << hour << " часа бактерий осталось " << currentBacteria << endl;
        
        hour++;
        antibioticEffect--;
        
        if (antibioticEffect <= 0)
        {
            break;
        }
        
        if (currentBacteria <= 0)
        {
            break;
        }
    }
    
    return 0;
}
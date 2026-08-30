#include <iostream>

using namespace std;

int main()
{
    float startAmplitude, stopAmplitude;
    
    cout << "Введите начальную амплитуду колебания (см): ";
    cin >> startAmplitude;
    cout << "Введите амплитуду, при которой маятник считается остановившимся (см): ";
    cin >> stopAmplitude;
    
    if (startAmplitude <= 0 || stopAmplitude <= 0)
    {
        cout << "Ошибка: амплитуды должны быть положительными!" << endl;
        return 1;
    }
    
    if (stopAmplitude >= startAmplitude)
    {
        cout << "Ошибка: конечная амплитуда должна быть меньше начальной!" << endl;
        return 1;
    }
    
    float currentAmplitude = startAmplitude;
    int swings = 0;
    
    while (currentAmplitude > stopAmplitude)
    {
        swings++;
        currentAmplitude *= 0.916; 
        
        cout << "Колебание " << swings << ": амплитуда = " << currentAmplitude << " см" << endl;
    }
    
    cout << "Маятник качнулся " << swings << " раз прежде чем остановиться." << endl;
    
    return 0;
}
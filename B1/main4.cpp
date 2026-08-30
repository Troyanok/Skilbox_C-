#include <iostream>

using namespace std;

int main() {
    // Пример массива из задания
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    
    // Находим минимум в массиве
    int min = numbers[0];
    for (int i = 1; i < 15; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    
    // Вычисляем сумму всех чисел в массиве
    int actualSum = 0;
    for (int i = 0; i < 15; i++)
    {
        actualSum += numbers[i];
    }
    
    // Вычисляем ожидаемую сумму 14 последовательных чисел
    // Формула суммы арифметической прогрессии: S = n/2 * (2a + (n-1)d)
    // где n=14, a=min, d=1
    int expectedSum = 14 * (2 * min + 13) / 2;  // 14/2 * (2*min + 13)
    
    // Разница между фактической и ожидаемой суммой - это повторяющееся число
    int duplicateNumber = actualSum - expectedSum;
    
    cout << "Повторяющееся число: " << duplicateNumber << endl;
    cout << "Начало последовательности (X): " << min << endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string secret, guess;
    
    cout << "Введите задуманное число: ";
    cin >> secret;
    
    cout << "Введите второе число: ";
    cin >> guess;
    
    // Проверяем, что оба числа четырехзначные
    if ((secret.length() != 4) || (guess.length() != 4))
    {
        cout << "Оба числа должны быть четырехзначными!" << endl;
        return 1;
    }
    
    int bulls = 0;
    int cows = 0;
    
    // Подсчитываем быков (точные совпадения)
    for (int i = 0; i < 4; i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
    }
    
    // Подсчитываем коров (цифра есть, но не на своем месте)
    // Используем частотный анализ для цифр 0-9
    int secretCount[10] = {0};
    int guessCount[10] = {0};
    
    // Считаем цифры, которые не являются быками
    for (int i = 0; i < 4; i++)
    {
        if (secret[i] != guess[i])
        {
            secretCount[secret[i] - '0']++;
            guessCount[guess[i] - '0']++;
        }
    }
    
    // Корова - это цифра, которая есть в обоих числах (не на своих местах)
    for (int i = 0; i < 10; i++)
    {
        cows += min(secretCount[i], guessCount[i]);
    }
    
    cout << "Быков: " << bulls << ", коров: " << cows << endl;
    
    return 0;
}
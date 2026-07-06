#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string targetFish;
    cout << "Какую рыбу вы хотите поймать? ";
    cin >> targetFish;

    ifstream riverFile("river.txt");
    if (!riverFile)
    {
        cerr << "Файл river.txt не найден." << endl;
        return -1;
    }

    ofstream basketFile("basket.txt", ios::app);
    if (!basketFile)
    {
        cerr << "Не удалось открыть basket.txt для записи." << endl;
        return -1;
    }

    string fish;
    int count = 0;
    while (getline(riverFile, fish))
    {
        // Убираем возможные пробельные символы в конце строки
        while (!fish.empty() && ((fish.back() == '\r') || (fish.back() == ' ')))
        {
            fish.pop_back();
        }
        if (fish == targetFish)
        {
            basketFile << fish << endl;
            count++;
        }
    }

    riverFile.close();
    basketFile.close();

    cout << "Поймано рыб вида \"" << targetFish << "\": " << count << endl;

    return 0;
}

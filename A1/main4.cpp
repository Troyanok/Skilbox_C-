#include <iostream>

using namespace std;

int main()
{
    int documentPrice = 4000000;
    int entranceCount = 10;
    int flatCount     = 40;

    cout << "Приветствуем вас в калькуляторе квартплаты! \n" << endl;
    cout << "Введите сумму, указанную в квитанции: " << documentPrice << endl;
    cout << "Сколько подъездов в вашем доме? " << entranceCount << endl;
    cout << "Сколько квартир в каждом подъезде? " << flatCount << endl;
    cout << "----Считаем-----" << endl;
    cout << "Каждая квартира должна платить по " << documentPrice / (entranceCount * flatCount)
         << " руб." << endl;

    return 0;
}
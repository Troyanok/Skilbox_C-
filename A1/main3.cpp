#include <iostream>

using namespace std;

int main()
{
    int shiftTime            = 480;
    int orderMinutes         = 2;
    int assembleOrderMinutes = 4;

    cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену. " << endl;
    cout << "Введите длительность смены в минутах: " << shiftTime << endl;
    cout << "Сколько минут клиент делает заказ? " << orderMinutes << endl;
    cout << "Сколько минут кассир собирает заказ? " << assembleOrderMinutes << endl;
    cout << "-----Считаем-----" << endl;
    cout << "За смену длиной " << shiftTime << " минут кассир успеет обслужить "
         << shiftTime / (orderMinutes + assembleOrderMinutes) << " клиентов." << endl;

    return 0;
}

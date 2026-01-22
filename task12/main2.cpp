#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Вектор цен
    vector<float> prices = {2.5, 4.25, 3.0, 10.0};

    // Вектор покупок (индексы товаров)
    vector<int> items = {1, 1, 0, 3};

    // Вычисляем суммарную стоимость
    float total = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        // Проверяем, что индекс в допустимых пределах
        if ((items[i] >= 0) && (items[i]) < (prices.size()))
        {
            total += prices[items[i]];
        }
        else
        {
            cout << "Предупреждение: элемент"
            << items[i] << "  вне допустимого диапазона!" << endl;
        }
    }

    cout << "Итоговая сумма: " << total << endl;

    return 0;
}
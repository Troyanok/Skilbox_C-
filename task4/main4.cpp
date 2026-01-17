#include <iostream>
#include <vector>

using namespace std;

const int MAX_AMOUNT = 150000;

const vector<int> MAS_NOMINATIONS = {5000, 2000, 1000, 500, 200, 100};

int main()
{
        int inputMoney;

        cout << "Введите сумму денег для снятия: ";
        cin >> inputMoney;

        if (inputMoney % 100 != 0)
        {
                cout << "Невозможно выдать сумму: сумма должна быть кратна 100" << endl;
                return -1;
        }

        if (inputMoney > MAX_AMOUNT)
        {
                cout << "Превышен лимит в 150 000 рублей" << endl;
                return -1;
        }

        vector<int> result(MAS_NOMINATIONS.size(), 0);

        for (size_t i = 0; i < result.size(); i++)
        {
                if (inputMoney >= MAS_NOMINATIONS[i])
                {
                        result[i] = inputMoney / MAS_NOMINATIONS[i];
                        inputMoney %= MAS_NOMINATIONS[i];
                }
        }

        if (inputMoney != 0)
        {
                cout << "Невозможно выдать сумму" << endl;
                return -1;
        }
        else
        {
                cout << "Купюры:" << endl;
                for (size_t i = 0; i < result.size(); i++)
                {
                        if (result[i] > 0)
                        {
                                cout << MAS_NOMINATIONS[i] << " руб: " << result[i] << " шт." << endl;
                        }
                }
        }

        return 0;
}

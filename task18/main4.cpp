#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int BANKNOTE_OPTIONS[] = {100, 200, 500, 1000, 2000, 5000};
const int COUNT_VAR_BANKNOTE = 6;
const int MAX_TOTAL_BILLS = 1000;
const string BIN_FILE = "current_result.bin";

struct CurrentBankState
{
    int bills[COUNT_VAR_BANKNOTE] = {0};
};

// Загрузка состояния из бинарного файла
bool LoadLastState(CurrentBankState& state)
{
    ifstream fin(BIN_FILE, ios::binary);
    if (!fin) 
    {
        return false;
    }
    fin.read(reinterpret_cast<char*>(&state), sizeof(state));
    return fin.good();
}

// Сохранение состояния в бинарный файл
void SaveCurrentState(const CurrentBankState& state)
{
    ofstream fout(BIN_FILE, ios::binary);
    fout.write(reinterpret_cast<const char*>(&state), sizeof(state));
}

// Вывод текущего состояния
void PrintState(const CurrentBankState& state)
{
    cout << "Состояние банкомата: " << endl;
    int totalBills = 0;
    int totalMoney = 0;
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
    {
        cout << BANKNOTE_OPTIONS[i] << " руб.: " << state.bills[i] << " шт." << endl;
        totalBills += state.bills[i];
        totalMoney += state.bills[i] * BANKNOTE_OPTIONS[i];
    }
    cout << "Всего купюр: " << totalBills << " (макс. 1000)" << endl;
    cout << "Общая сумма: " << totalMoney << " руб." << endl;
}

// Пополнение
void AddMoneyState(CurrentBankState& state)
{
    int newBills[COUNT_VAR_BANKNOTE];
    cout << "Введите количество купюр для каждого номинала (100,200,500,1000,2000,5000):" << endl;
    int currentTotal = 0;
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++) 
    {
        currentTotal += state.bills[i];
    }
    int addedTotal = 0;
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
    {
        cout << BANKNOTE_OPTIONS[i] << ": ";
        cin >> newBills[i];
        if (newBills[i] < 0)
        {
            cout << "Количество не может быть отрицательным. Операция отменена." << endl;
            return;
        }
        addedTotal += newBills[i];
    }
    if (currentTotal + addedTotal > MAX_TOTAL_BILLS)
    {
        cout << "Превышена максимальная ёмкость (1000 купюр). Пополнение невозможно." << endl;
        return;
    }
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
    {
        state.bills[i] += newBills[i];
    }
    SaveCurrentState(state);
    cout << "Пополнение выполнено." << endl;
}

// Снятие денег
void SubMoneyState(CurrentBankState& state)
{
    int amount;
    cout << "Введите сумму для снятия: ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Сумма должна быть положительной." << endl;
        return;
    }

    // Жадный алгоритм: пробуем выдать крупными купюрами
    int toSubMoneyState[COUNT_VAR_BANKNOTE] = {0};
    int remaining = amount;
    for (int i = COUNT_VAR_BANKNOTE - 1; i >= 0; i--)
    {
        int needed = remaining / BANKNOTE_OPTIONS[i];
        int take = min(needed, state.bills[i]);
        toSubMoneyState[i] = take;
        remaining -= take * BANKNOTE_OPTIONS[i];
    }

    if (remaining > 0)
    {
        cout << "Невозможно выдать запрошенную сумму имеющимися купюрами." << endl;
        return;
    }

    // Списываем купюры
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
    {
        state.bills[i] -= toSubMoneyState[i];
    }
    SaveCurrentState(state);

    cout << "Выдано:" << endl;
    for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
    {
        if (toSubMoneyState[i] > 0)
        {
            cout << BANKNOTE_OPTIONS[i] << " x " << toSubMoneyState[i] 
                 << " = " << BANKNOTE_OPTIONS[i] * toSubMoneyState[i] 
                 << " руб." << endl;
        }
    }
}

int main()
{
    CurrentBankState bankState;

    if (LoadLastState(bankState))
    {
        cout << "Загружено сохранённое состояние банкомата." << endl;
    }
    else
    {
        cout << "Файл состояния не найден. Банкомат пуст." << endl;
        {
            for (int i = 0; i < COUNT_VAR_BANKNOTE; i++)
            {
                bankState.bills[i] = 0;
            }
        }
    }

    string command;
    while (1)
    {
        cout << "Выберите действие (+ пополнение, - снятие, q выход): ";
        cin >> command;
        if (command == "q" || command == "Q")
        {
            break;
        }
        if (command == "+")
        {
            AddMoneyState(bankState);
            PrintState(bankState);
        }
        else if (command == "-")
        {
            SubMoneyState(bankState);
            PrintState(bankState);
        }
        else
        {
            cout << "Неизвестная команда." << endl;
        }
    }

    cout << "Завершение работы." << endl;
    return 0;
}

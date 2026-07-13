#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> queue;
    string input;
    string command;

    cout << "Добро пожаловать в регистратуру: " << endl; 
    while (1)
    {
        cout << "Выберите команду для работы регистратуры: " << endl;
        cout << "\t add: Добавить человека в очередь;" << endl;
        cout << "\t Next: Вызвать человека в регистратуру по алфавитному порядку, который первый в очереди;" << endl;
        cout << "\t quit: Завершить работу программы."<< endl;
        cin >> command;
        cin.ignore();

        if (command == "quit")
        {
            break;
        }

        if (command == "Next")
        {

            if (!queue.empty())
            {
                auto it = queue.begin();
                cout << it->first << endl;
                if (--(it->second) == 0)
                {
                    queue.erase(it);
                }
            }
            else 
            {
                cout << "Очередь пустая!" << endl;
            }
        }
        else if (command == "add")
        {
            cout << "Введите строку: ";
            getline(std::cin, input);

            if (input.empty()) 
            {
                cout << "Введена пустая строка!" << endl;
                continue;
            }
            queue[input] += 1;
        }
        else
        {
            cout << "Была введена неизвестная команда!" << endl;
        }
        cout << endl;
    }
    return 0;
}

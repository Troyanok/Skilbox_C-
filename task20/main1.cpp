#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{

    map<string, string> phoneToSurname;
    map<string, vector<string>> surnameToPhones;

    string command {};
    string line {};

    cout << "Добро пожаловать в Телефонный справочник" << endl;
    while (1)
    {
        cout << "Выберите команду для работы справочника: " << endl;
        cout << "\t add: Добавить номер и фамилию в справочник через пробел;" << endl;
        cout << "\t phone: Найти фамилию в справочнике по номеру телефона;" << endl;
        cout << "\t surname: Найти номер телефона в справочнике по фамилии;" << endl;
        cout << "\t quit: Завершить работу программы."<< endl;
        cin >> command;
        cin.ignore();

        if (command == "quit")
        {
            break;
        }

        cout << "Введите строку: ";
        getline(std::cin, line);

        if (line.empty())
        {
            continue;
        }

        if (command == "add")
        {
            size_t spacePos = line.find(' ');
            if (spacePos != string::npos)
            {
                string phone = line.substr(0, spacePos);
                string surname = line.substr(spacePos + 1);
                phoneToSurname[phone] = surname;
                surnameToPhones[surname].push_back(phone);
                cout << "Телефон и фамилия успешно добавлены в справочник" << endl;
            }
            else
            {
                cout << "Ошибка в вводе телефона и фамилии, нет разделителя!" << endl;
            }
        }
        else if (command == "phone")
        {
            if (isdigit(line[0]) || line[0] == '-')
            {
                auto it = phoneToSurname.find(line);
                if (it != phoneToSurname.end())
                {
                    cout << "Фамилия: " << it->second << " по номеру телефона: " << it->first << endl;
                }
                else
                {
                    cout << "Указанный номер не был добавлен в справочник!" << endl;
                }
            }
            else
            {
                cout << "Указанный номер некорретный!" << endl;
            }
        }
        else if (command == "surname")
        {
            auto it = surnameToPhones.find(line);
            if (it != surnameToPhones.end())
            {
                const auto& phones = it->second;
                cout << "Телефон: " << it->first << "по номеру телефонов" << endl;
                for (size_t i = 0; i < phones.size(); ++i)
                {
                    if (i > 0) 
                    {
                        cout << " ";
                    }
                    cout << phones[i];
                }
                cout << endl;
            }
            else
            {
                cout << "Указанная фамилия не была добавлен в справочник!" << endl;
            }
        }
        else
        {
            cout << "Была введена неизвестная команда!" << endl;
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdint> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string BIN_FILE = "current_result.bin";

struct Statement
{
    string personName;
    string personSurname;
    string formatDate;
    string money;

    Statement() 
        : personName("")
        , personSurname("")
        , formatDate("")
        , money("") 
    {};
};

void WriteString(ostream& outputStream, const string& str)
{
    int len = str.length();
    outputStream.write((char*)(&len), sizeof(len));
    outputStream.write(str.c_str(), len);
}

void WriteStatement(ostream& outputStream, const Statement& st)
{
    WriteString(outputStream, st.personName);
    WriteString(outputStream, st.personSurname);
    WriteString(outputStream, st.formatDate);
    WriteString(outputStream, st.money);
}

void SaveAllStatement(const vector<Statement>& allStates)
{
    ofstream file(BIN_FILE, ios::binary | ios::trunc);
    if (!file)
    {
        cout << "Не удалось открыть файл для записи!" << endl;
        return;
    }

    for (const auto& st : allStates)
    {
        WriteStatement(file, st);
    }

    if (!file.good())
    {
        cout << "Ошибка во время записи файла!" << endl;
    }
}

bool ReadString(istream& inputStream, string& str)
{
    uint32_t len = 0;
    inputStream.read((char*)(&len), sizeof(len));
    if (inputStream.fail())
    {
        return false;
    }

    if (len > 1024)
    {   
        return false;
    }

    str.resize(len);
    inputStream.read((char*)str.c_str(), len);
    return !inputStream.fail();
}

bool ReadStatement(istream& inputStream, Statement& state)
{
    if (!ReadString(inputStream, state.personName))
    {
        return false;
    }
    if (!ReadString(inputStream, state.personSurname))
    {
        return false;
    }
    if (!ReadString(inputStream, state.formatDate))
    {
        return false;
    }
    if (!ReadString(inputStream, state.money))
    {
        return false;
    }
    return !inputStream.fail();
}

void LoadAllStatement(vector<Statement>& allStates)
{
    allStates.clear();
    ifstream file(BIN_FILE, ios::binary);
    if (!file)
    {
        return;
    }

    Statement temp;
    while (ReadStatement(file, temp))
    {
        allStates.push_back(temp);
    }

    // Проверяем, почему остановились
    if (file.eof())
    {
        // Дошли до конца. Если в конце остались неполные данные, они проигнорированы.
        if (file.gcount() > 0)
        {
            cout << "Предупреждение: в конце файла неполная запись." << endl;
        }
    }
    else if (file.fail())
    {
        cout << "Ошибка чтения файла или данные повреждены." << endl;
    }

}

int main()
{
    string inputCommand;
    vector<Statement> statements;

    while(1)
    {
        cout << "Выберите действие (list прочитать и вывести из файла ведомости, add добавить новую ведомость в файл, q выход): ";
        cin >> inputCommand;

        if (inputCommand == "list")
        {
            LoadAllStatement(statements);
            if (statements.empty())
            {
                cout << "Ведомость пуста." << endl;
            }
            else
            {
                cout << "Содержимое ведомости:" << endl;
                for (const auto& st : statements)
                {
                    cout << "Имя: " << st.personName << "\t" << "Фамилия: " << st.personSurname
                         << "\t" << "Дата выдачи: " << st.formatDate << "\t" << "Сумма выплаты: " 
                         << st.money<< " в руб."<< endl;
                }
            }
        }
        else if (inputCommand == "add")
        {
            LoadAllStatement(statements);

            Statement newSt;
            cout << "Введите имя: ";
            cin >> newSt.personName;
            cout << "Введите фамилию: ";
            cin >> newSt.personSurname;
            cout << "Введите дату (ДД.ММ.ГГГГ): ";
            cin >> newSt.formatDate;
            cout << "Введите сумму в рублях: ";
            cin >> newSt.money;

            statements.push_back(newSt);
            SaveAllStatement(statements);
            cout << "Запись добавлена." << endl;
        }
        else if (inputCommand == "q")
        {
            break;
        }
        else
        {
            cout << "Неизвестная команда!" << endl;
        }
    }

    return 0;
}

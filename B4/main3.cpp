#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string input;
    cout << "Введите выражение (например, 3.5+2.1): ";
    cin >> input;

    stringstream bufferStream(input);
    double a, b;
    char op;
    bufferStream >> a >> op >> b;

    double result = 0.0;
    switch (op)
    {
        case '+':
        {
            result = a + b;
            break;
        }
        case '-':
        {
            result = a - b;
            break;
        }
        case '*':
        {
            result = a * b;
            break;
        }
        case '/':
        {
            if (b != 0.0)
            {
                result = a / b;
            }
            else
            {
                cout << "Ошибка: деление на ноль!" << endl;
                return -1;
            }
            break;
        }
        default:
        {
            cout << "Неизвестная операция!" << endl;
            return -1;
        }
    }

    cout << "Результат: " << result << endl;
    return 0;
}

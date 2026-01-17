#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Введите номер последовательности: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Номер должен быть положительным." << endl;
        return -1;
    }

    const long long MAX_VALUE = 2147483647LL;
    long long fib_current = 0;
    long long fib1 = 1, fib2 = 1;

    if ((n == 1) || (n == 2))
    {
        fib_current = 1;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            fib_current = fib1 + fib2;
            
            if (fib_current > MAX_VALUE)
            {
                cout << "Число Фибоначчи для N = " << n << " превышает 2147483647." << endl;
                return -1;
            }

            fib1 = fib2;
            fib2 = fib_current;
        }
    }

    cout << "Число в последовательности: " << fib_current << endl;

    return 0;
}
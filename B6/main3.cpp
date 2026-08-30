#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void evendigits(long long n, int& ans)
{
    if (n == 0)
    {
        ans = 0;
        return;
    }
    if (n < 10)
    {
        ans = (n % 2 == 0) ? 1 : 0;
        return;
    }
    evendigits(n / 10, ans);
    if ((n % 10) % 2 == 0)
    {
        ans++;
    }
}

int main()
{
    int ans = 0;
    evendigits(9223372036854775806, ans);
    
    cout << "Количество чётных символов: " << ans << endl;
    return 0;
}

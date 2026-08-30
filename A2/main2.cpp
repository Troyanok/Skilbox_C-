#include <iostream>

using namespace std;

int main()
{
    int a = 42;
    int b = 153;
    cout << "a: " << a << endl; /* На экран будет выведено 42 */
    cout << "b: " << b << endl; /* На экран будет выведено 153 */

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "a: " << a << endl; /* На экран будет выведено 153 */
    cout << "b: " << b << endl; /* На экран будет выведено 42 */
    return 0;
}
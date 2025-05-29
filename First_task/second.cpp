#include <iostream>

using namespace std;

int main()
{
    int basePrice   = 17000;
    int increment   = 2000;
    int delivery    = 4000;

    cout << "Стоимость товара: " << basePrice + increment - delivery << endl;
    
    return 0;
}
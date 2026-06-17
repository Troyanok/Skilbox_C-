#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void reverse(int* arr, int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(data) / sizeof(int);
    reverse(data, length);

    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}

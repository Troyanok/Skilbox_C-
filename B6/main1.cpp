#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void swapvec(vector<int>& first, int* second)
{
    int length = std::min(first.size(), (sizeof(second) / sizeof(int)));
    for (int i = 0; i < length; i++)
    {
        int temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

int main()
{
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);

    for(int i = 0; i < 4; ++i)
    {
        std::cout << a[i];
    }
    std::cout << std::endl;

    for(int i = 0; i < 4; ++i)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;
    return 0;
}

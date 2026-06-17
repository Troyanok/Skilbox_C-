#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void CountRabbitJump(int n, int k, vector<int>&path, int& totalCount)
{
    if (n < 0)
    {
        return;
    }
    
    if (n == 0)
    {
        cout << "(";
        for (size_t i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i + 1 < path.size())
            {
                cout << ",";
            }
        }
        cout << ")" << endl;
        totalCount++;
        return;
    }
    
    for (int jump = 1; jump <= k; jump++)
    {
        path.push_back(jump);
        CountRabbitJump(n - jump, k, path, totalCount);
        path.pop_back();
    }
}

int main()
{
    int total = 0;
    int n = 3;
    int k = 2;
    vector<int> path = {};
    CountRabbitJump(n, k, path, total);
    
    cout << "Всего способов: " << total << endl;
    return 0;
}

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream file("data.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return -1;
    }

    string userName;
    string userSername;
    double userValue;
    string userDate;

    string maxValueUserName = "";
    string maxValueUserSername = "";
    double maxUserValue = 0;
    double totalValue = 0;

    while (file >> userName >> userSername >> userValue >> userDate)
    {
        totalValue += userValue;
        if (userValue > maxUserValue)
        {
            maxValueUserName = userName;
            maxValueUserSername = userSername;
            maxUserValue = userValue;
        }
    }

    file.close();

    cout << "Общее количество выплаченных средств: " << totalValue << endl;
    cout << "Человек с максимальной выплатой: " <<  maxValueUserName << " " << maxValueUserSername << " стоимость: " << maxUserValue << endl;

    return 0;
}

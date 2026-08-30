#include <iostream>
#include <include/company.h>

int main()
{
    int teamCount, workersPerTeam;
    std::cout << "Enter number of teams and workers per team: ";
    std::cin >> teamCount >> workersPerTeam;

    Company company(teamCount, workersPerTeam);
    company.Run();

    return 0;
}
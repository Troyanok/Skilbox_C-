#include <include/company.h>
#include <iostream>

Company::Company(int teamCount, int workersPerTeam)
{
    for (int i = 0; i < teamCount; ++i)
    {
        auto team = std::make_unique<Team>("Team " + std::to_string(i + 1), workersPerTeam);
        auto manager = std::make_unique<Manager>("Manager " + std::to_string(i + 1), i + 1);
        team->SetManager(std::move(manager));
        teams_.push_back(std::move(team));
    }
}

void Company::DisplayAllTeams() const
{
    for (const auto& team : teams_)
    {
        team->DisplayStatus();
    }
}

bool Company::AllWorkersBusy() const
{
    for (const auto& team : teams_)
    {
        if (!team->AllWorkersBusy())
        {
            return false;
        }
    }
    return true;
}

void Company::Run()
{
    std::cout << "Initial state:" << std::endl;
    DisplayAllTeams();

    int directive;
    while (!AllWorkersBusy())
    {
        std::cout << "Enter director's directive (integer): ";
        std::cin >> directive;
        std::cout << "Processing directive " << directive << std::endl;
        for (auto& team : teams_)
        {
            team->GetManager()->ProcessDirective(directive);
        }
        std::cout << std::endl;
        std::cout << "Current state:" << std::endl;
        DisplayAllTeams();
    }
    std::cout << "All workers are busy. Program finished." << std::endl;
}
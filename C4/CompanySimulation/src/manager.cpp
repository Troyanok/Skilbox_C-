#include <include/manager.h>
#include <include/team.h>
#include <cstdlib>
#include <iostream>

void Manager::ProcessDirective(int directive)
{
    if (team_ == nullptr)
    {
        return;
    }

    auto& workers = team_->GetWorkers();
    int workerCount = workers.size();
    if (workerCount == 0)
    {
        return;
    }

    std::srand(directive + id_);
    int tasksCount = std::rand() % (workerCount + 1);
    if (tasksCount == 0)
    {
        tasksCount = 1;
    }

    int assigned = 0;
    for (auto* worker : workers)
    {
        if (assigned >= tasksCount)
        {
            break;
        }
        if (!worker->IsBusy())
        {
            int taskRand = std::rand() % 3;
            TaskType task;
            switch (taskRand)
            {
                case 0:
                    task = TaskType::A;
                    break;
                case 1:
                    task = TaskType::B;
                    break;
                default:
                    task = TaskType::C;
            }
            worker->AssignTask(task);
            assigned++;
            std::cout << "  " << worker->GetName() << " performs task "
                      << static_cast<char>('A' + static_cast<int>(task)) << "\n";
        }
    }
    std::cout << "Manager " << name_ << " assigned " << assigned << " tasks\n";
}
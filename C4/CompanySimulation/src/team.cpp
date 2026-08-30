#include <include/team.h>
#include <iostream>

Team::Team(const std::string& name, int workerCount) : name_(name)
{
    for (int i = 0; i < workerCount; ++i)
    {
        workers_.push_back(std::make_unique<Worker>("Worker " + std::to_string(i + 1)));
    }
}

void Team::AddWorker(std::unique_ptr<Worker> worker)
{
    workers_.push_back(std::move(worker));
}

Manager* Team::GetManager() const
{
    return manager_.get();
}

void Team::SetManager(std::unique_ptr<Manager> manager)
{
    manager_ = std::move(manager);
    manager_->SetTeam(this);
}

std::vector<Worker*>& Team::GetWorkers()
{
    static thread_local std::vector<Worker*> rawWorkers;
    rawWorkers.clear();
    for (auto& w : workers_)
    {
        rawWorkers.push_back(w.get());
    }
    return rawWorkers;
}

void Team::DisplayStatus() const
{
    std::cout << "Team " << name_ << " - Manager " << (manager_ ? manager_->GetName() : "none") << "\n";
    for (const auto& worker : workers_)
    {
        std::cout << "         " << worker->GetName() << " ";
        if (worker->IsBusy())
        {
            char taskChar = static_cast<char>('A' + static_cast<int>(*worker->GetCurrentTask()));
            std::cout << "performs task \"" << taskChar << "\"";
        }
        else
        {
            std::cout << "free";
        }
        std::cout << std::endl;
    }
    std::cout << "         ----" << std::endl;
}

bool Team::AllWorkersBusy() const
{
    for (const auto& worker : workers_)
    {
        if (!worker->IsBusy())
        {
            return false;
        }
    }
    return true;
}

std::string Team::GetName() const
{
    return name_;
}
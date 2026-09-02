#include <include/swimmer.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <iomanip>

Swimmer::Swimmer(const std::string& name, double speed)
    : name_(name)
    , speed_(speed)
    , distance_(0.0)
    , finishTime_(0.0)
    , finished_(false)
{}

void Swimmer::StartSwim()
{
    auto start = std::chrono::steady_clock::now();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(dataMutex_);
            distance_ += speed_;
            if (distance_ >= 100.0)
            {
                distance_ = 100.0;
                finished_ = true;
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                finishTime_ = elapsed.count();
                break;
            }
        }
    }
}

const std::string& Swimmer::GetName() const
{
    return name_;
}

double Swimmer::GetDistance() const
{
    std::lock_guard<std::mutex> lock(dataMutex_);
    return distance_;
}

double Swimmer::GetTime() const
{
    std::lock_guard<std::mutex> lock(dataMutex_);
    return finishTime_;
}

bool Swimmer::IsFinished() const
{
    std::lock_guard<std::mutex> lock(dataMutex_);
    return finished_;
}

void Swimmer::PrintCurrentStatus(const std::vector<Swimmer*>& swimmers)
{
    std::cout << "Current status:" << std::endl;
    for (const auto* s : swimmers)
    {
        std::cout << s->GetName() << ": " << std::fixed << std::setprecision(2)
                  << s->GetDistance() << " m" << std::endl;
    }
    std::cout << std::endl;
}

bool Swimmer::AllFinished(const std::vector<Swimmer*>& swimmers)
{
    for (const auto* s : swimmers)
    {
        if (!s->IsFinished())
        {
            return false;
        }
    }
    return true;
}

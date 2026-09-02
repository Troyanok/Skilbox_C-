#include <include/station.h>
#include <iostream>

Station::Station() : occupied_(false)
{}

void Station::Arrive(const std::string& trainName)
{
    std::unique_lock<std::mutex> lock(mtx_);
    cvArrive_.wait(lock, [this]
    {
        return !occupied_;
    });
    occupied_ = true;
    currentTrain_ = trainName;
    std::cout << "Train " << trainName << " is at the station." << std::endl;
    cvDepart_.notify_all();
}

void Station::Depart(const std::string& trainName)
{
    std::lock_guard<std::mutex> lock(mtx_);
    if (currentTrain_ == trainName)
    {
        occupied_ = false;
        currentTrain_.clear();
        cvArrive_.notify_all();
    }
}

bool Station::IsOccupied() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    return occupied_;
}

std::string Station::GetCurrentTrain() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    return currentTrain_;
}

void Station::WaitForDepartCommand()
{
    std::unique_lock<std::mutex> lock(mtx_);
    cvDepart_.wait(lock, [this]
    {
        return currentTrain_.empty();
    });
}

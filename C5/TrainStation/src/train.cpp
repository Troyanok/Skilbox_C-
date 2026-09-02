#include <include/train.h>
#include <include/station.h>
#include <iostream>
#include <chrono>

Train::Train(const std::string& name, int travelTime, Station* station)
    : name_(name)
    , travelTime_(travelTime)
    , station_(station)
    , visitedStation_(false)
{}

void Train::Start()
{
    thread_ = std::thread(&Train::Run, this);
}

void Train::Join()
{
    if (thread_.joinable())
    {
        thread_.join();
    }
}

void Train::Run()
{
    std::this_thread::sleep_for(std::chrono::seconds(travelTime_));
    std::cout << "Train " << name_ << " arrived at station.\n";
    station_->Arrive(name_);
    visitedStation_ = true;
    station_->WaitForDepartCommand();
    std::cout << "Train " << name_ << " departed from station.\n";
    station_->Depart(name_);
}

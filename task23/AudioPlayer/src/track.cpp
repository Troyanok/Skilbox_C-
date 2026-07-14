#include <include/track.h>

#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

Track::Track()
    : audioName_({})
    , creationDate_({})
    , durationSec_(0)
{}

Track::Track(const std::string& name, const std::tm& create, int durationSec)
    : audioName_(name)
    , creationDate_(create)
    , durationSec_(durationSec)
{}

std::string Track::GetTrackName() const { return audioName_; }
std::tm Track::GetTrackCreationDate() const { return creationDate_; }
int Track::GetTrackDurationSec() const { return durationSec_; }

void Track::PrintTrackData() const
{
    std::cout << "Текущий трек: " << audioName_ << std::endl;

    // Преобразование секунд в ЧЧ:ММ:СС
    int hours = durationSec_ / 3600;
    int minutes = (durationSec_ % 3600) / 60;
    int seconds = durationSec_ % 60;
    std::cout << "Длительность трека: "
              << hours << ":"
              << (minutes < 10 ? "0" : "") << minutes << ":"
              << (seconds < 10 ? "0" : "") << seconds << std::endl;

    std::cout << "Дата создания трека: "
              << (creationDate_.tm_year + 1900) << "-"
              << (creationDate_.tm_mon + 1) << "-"
              << creationDate_.tm_mday << " "
              << creationDate_.tm_hour << ":"
              << creationDate_.tm_min << ":"
              << creationDate_.tm_sec << std::endl;
}

std::vector<Track> ReadTracksFromFile(const std::string& filename)
{
    std::vector<Track> tracks;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return tracks;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string name, dateStr, timeStr;
        if (!std::getline(iss, name, '\t') ||
            !std::getline(iss, dateStr, '\t') ||
            !std::getline(iss, timeStr, '\t'))
        {
            continue; 
        }

        std::tm creationDate = {};
        std::istringstream ds(dateStr);
        ds >> std::get_time(&creationDate, "%Y-%m-%d");
        if (ds.fail())
        {
            std::cout << "Ошибка даты: " << dateStr << std::endl;
            continue;
        }

        int hours = 0, mins = 0, secs = 0;
        char colon1, colon2;
        std::istringstream ts(timeStr);
        if (!(ts >> hours >> colon1 >> mins >> colon2 >> secs) || colon1 != ':' || colon2 != ':')
        {
            std::cout << "Ошибка длительности: " << timeStr << std::endl;
            continue;
        }
        int totalSec = hours * 3600 + mins * 60 + secs;

        tracks.emplace_back(name, creationDate, totalSec);
    }
    return tracks;
}

#include <include/audio_player.h>

#include <algorithm>
#include <iostream>
#include <cstdlib>   
#include <ctime>

AudioPlayer::AudioPlayer()
    : isPlay_(false)
    , isPause_(false)
{
}

AudioPlayer::AudioPlayer(const std::string& fileName)
    : isPlay_(false)
    , isPause_(false)
{
    audioList_ = ReadTracksFromFile(fileName);
    std::cout << "Загруженные треки:\n";
    for (const auto& t : audioList_)
        std::cout << " - " << t.GetTrackName() << std::endl;
}

void AudioPlayer::PlayTrack(const std::string& targetName)
{
    if (isPlay_)
    {
        return;
    }

    auto it = std::find_if(audioList_.begin(), audioList_.end(),
        [&targetName](const Track& t) { return t.GetTrackName() == targetName; });

    if (it != audioList_.end())
    {
        it->PrintTrackData();
        std::cout << "Воспроизведение трека!" << std::endl;
        currentTrack_ = *it;
        isPlay_ = true;
        isPause_ = false;
    }
    else
    {
        std::cout << "Трек \"" << targetName << "\" не найден." << std::endl;
    }
}

void AudioPlayer::StopTrack()
{
    if (isPlay_)
    {
        std::cout << "Останов трека: " << currentTrack_.GetTrackName() << std::endl;
        isPlay_ = false;
        isPause_ = false;
    }
}

void AudioPlayer::PauseTrack()
{
    if (isPlay_ && !isPause_)
    {
        isPause_ = true;
        std::cout << "Пауза при воспроизведении трека: " << currentTrack_.GetTrackName() << std::endl;
    }
}

void AudioPlayer::NextTrack()
{
    if (audioList_.empty())
    {
        std::cout << "Плейлист пуст." << std::endl;
        return;
    }

    isPlay_ = false;
    isPause_ = false;

    int index = rand() % audioList_.size();
    std::cout << "Переход к следующему треку (shuffle)..." << std::endl;
    PlayTrack(audioList_[index].GetTrackName());
}

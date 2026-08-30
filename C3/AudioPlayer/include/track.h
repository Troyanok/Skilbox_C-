#pragma once

#include <string>
#include <ctime>
#include <vector>

/// @brief Класс для хранения информации о треке
class Track
{
public:
    /// @brief Конструктор по умолчанию
    Track();

    /// @brief Конструктор 
    /// @param[in] name Имя трека
    /// @param[in] create Время создания трека
    /// @param[in] durationSec Длительность трека
    Track(const std::string& name, const std::tm& create, int durationSec);

    /// @brief Деструктор по умолчанию
    ~Track() = default;

    /// @brief Получить имя трека
    /// @return Имя трека
    std::string GetTrackName() const;

    /// @brief Получить дату создания трека
    /// @return Дата создания трека
    std::tm GetTrackCreationDate() const;

    /// @brief Получить длительность трека в секундах
    /// @return Длительность трека в секундаъ
    int GetTrackDurationSec() const;  

    /// @brief Напечатать информацию о треке
    void PrintTrackData() const;

private:
    std::string audioName_; ///< Имя трека
    std::tm creationDate_;  ///< Дата создания трека
    int durationSec_;       ///< Длительность трека в секундах
};

/// @brief Получить плейлист треков из файла
/// @param[in] fileName Имя файла
/// @return Вектор треков
std::vector<Track> ReadTracksFromFile(const std::string& filename);

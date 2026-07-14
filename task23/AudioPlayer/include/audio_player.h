#include <iostream>
#include <include/track.h>

/// @brief Класс аудиоплеера
class AudioPlayer
{
public:
    /// @brief Конструктор по умолчанию
    AudioPlayer();

    /// @brief Конструктор
    /// @param[in] fileName Имя файла для получения вектора треков
    AudioPlayer(const std::string& fileName);

    /// @brief Деструктор по умолчания
    ~AudioPlayer() = default;

    /// @brief Воспроизвести трек
    /// @param[in] targetName Имя трека для воспроизведения
    void PlayTrack(const std::string& targetName);

    /// @brief Остановить воспроизведение трека
    void StopTrack();

    /// @brief Поставить на паузу воспроизведение трека
    void PauseTrack();

    /// @brief Переключиться на следующий трек
    void NextTrack();

private:
    std::vector<Track> audioList_; ///< Вектор треков
    bool isPlay_;                  ///< Флаг воспроизведения
    bool isPause_;                 ///< Флаг паузы
    Track currentTrack_;           ///< Текущий трек
};

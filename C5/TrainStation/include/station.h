#pragma once

#include <string>
#include <mutex>
#include <condition_variable>

/// @brief Класс, представляющий железнодорожный вокзал
class Station
{
public:
    /// @brief Конструктор по умолчанию
    Station();

    /// @brief Прибытие поезда на станцию
    /// @param trainName Имя прибывающего поезда
    void Arrive(const std::string& trainName);

    /// @brief Отправление поезда со станции
    /// @param trainName Имя отправляющегося поезда
    void Depart(const std::string& trainName);

    /// @brief Проверяет, занята ли станция
    /// @return true если поезд на станции
    bool IsOccupied() const;

    /// @brief Возвращает имя поезда на станции
    /// @return Имя или пустая строка
    std::string GetCurrentTrain() const;

    /// @brief Ожидает, пока currentTrain не станет пустым
    void WaitForDepartCommand();

private:
    mutable std::mutex mtx_;
    std::condition_variable cvArrive_;
    std::condition_variable cvDepart_;
    std::string currentTrain_;
    bool occupied_;
};

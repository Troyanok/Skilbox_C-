#pragma once

#include <string>
#include <thread>

class Station;

/// @brief Класс, представляющий поезд
class Train
{
public:
    /// @brief Конструктор поезда
    /// @param name Условное обозначение (A, B, C)
    /// @param travelTime Время в пути до вокзала (секунды)
    /// @param station Указатель на объект станции
    Train(const std::string& name, int travelTime, Station* station);

    /// @brief Запускает поток поезда
    void Start();

    /// @brief Ожидает завершения потока поезда
    void Join();

    /// @brief Проверяет, посетил ли поезд станцию
    /// @return true если посетил
    bool HasVisitedStation() const
    {
        return visitedStation_;
    }

private:
    /// @brief Основной метод потока
    void Run();

    std::string name_;      ///< Имя поезда
    int travelTime_;        ///< Время в пути
    Station* station_;      ///< Указатель на станцию
    bool visitedStation_;   ///< Флаг посещения станции
    std::thread thread_;    ///< Поток поезда
};

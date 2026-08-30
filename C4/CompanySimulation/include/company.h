#pragma once

#include <vector>
#include <memory>
#include <include/team.h>

/// @brief Класс, представляющий компанию
class Company
{
public:
    /// @brief Конструктор компании
    /// @param teamCount Количество команд
    /// @param workersPerTeam Количество работников в команде
    Company(int teamCount, int workersPerTeam);

    /// @brief Запускает основной цикл симуляции
    void Run();

    /// @brief Проверяет, все ли работники заняты
    /// @return true если все заняты
    bool AllWorkersBusy() const;

    /// @brief Выводит состояние всех команд
    void DisplayAllTeams() const;

private:
    std::vector<std::unique_ptr<Team>> teams_; ///< Вектор команд
};
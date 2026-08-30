#pragma once

#include <string>
#include <vector>
#include <memory>
#include <include/worker.h>
#include <include/manager.h>

/// @brief Класс, представляющий команду работников
class Team
{
public:
    /// @brief Конструктор команды
    /// @param name Название команды
    /// @param workerCount Количество работников
    Team(const std::string& name, int workerCount);

    /// @brief Добавляет работника в команду
    /// @param worker Умный указатель на работника
    void AddWorker(std::unique_ptr<Worker> worker);

    /// @brief Возвращает указатель на менеджера
    /// @return Указатель на Manager или nullptr
    Manager* GetManager() const;

    /// @brief Назначает менеджера команде
    /// @param manager Умный указатель на менеджера
    void SetManager(std::unique_ptr<Manager> manager);

    /// @brief Возвращает вектор сырых указателей на работников
    /// @return Вектор указателей
    std::vector<Worker*>& GetWorkers();

    /// @brief Выводит текущее состояние команды
    void DisplayStatus() const;

    /// @brief Проверяет, все ли работники заняты
    /// @return true если все заняты
    bool AllWorkersBusy() const;

    /// @brief Возвращает название команды
    /// @return Название
    std::string GetName() const;

private:
    std::string name_;                             ///< Название команды
    std::unique_ptr<Manager> manager_;             ///< Менеджер
    std::vector<std::unique_ptr<Worker>> workers_; ///< Работники
};
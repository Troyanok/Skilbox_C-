#pragma once

#include <string>
#include <optional>
#include <include/common.h>

/// @brief Класс, представляющий работника
class Worker
{
public:
    /// @brief Конструктор работника
    /// @param name Имя работника
    Worker(const std::string& name): name_(name){};

    /// @brief Назначает задачу работнику
    /// @param task Тип задачи
    void AssignTask(TaskType task)
    {
        currentTask_ = task;
    }

    /// @brief Проверяет, занят ли работник
    /// @return true если есть текущая задача
    bool IsBusy() const
    {
        return currentTask_.has_value();
    }

    /// @brief Возвращает имя работника
    /// @return Имя
    std::string GetName() const
    {
        return name_;
    }

    /// @brief Возвращает текущую задачу
    /// @return std::optional<TaskType>
    std::optional<TaskType> GetCurrentTask() const
    {
        return currentTask_;
    }

private:
    std::string name_;                      ///< Имя работника
    std::optional<TaskType> currentTask_;   ///< Текущая задача (если назначена)
};
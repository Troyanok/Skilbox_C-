#pragma once

#include <string>
#include <mutex>
#include <vector>
#include <chrono>

/// @brief Класс, представляющий пловца в соревновании
class Swimmer
{
public:
    /// @brief Конструктор пловца
    /// @param name Имя пловца
    /// @param speed Скорость в метрах в секунду
    Swimmer(const std::string& name, double speed);

    /// @brief Запускает процесс плавания в отдельном потоке
    void StartSwim();

    /// @brief Возвращает имя пловца
    /// @return Имя
    const std::string& GetName() const;

    /// @brief Возвращает текущее расстояние (с защитой мьютексом)
    /// @return Пройденное расстояние в метрах
    double GetDistance() const;

    /// @brief Возвращает время финиша (если завершил)
    /// @return Время в секундах или 0, если ещё не финишировал
    double GetTime() const;

    /// @brief Проверяет, завершил ли пловец дистанцию
    /// @return true если финишировал
    bool IsFinished() const;

    /// @brief Выводит текущее состояние всех пловцов
    /// @param swimmers Вектор указателей на пловцов
    static void PrintCurrentStatus(const std::vector<Swimmer*>& swimmers);

    /// @brief Проверяет, все ли пловцы завершили заплыв
    /// @param swimmers Вектор указателей на пловцов
    /// @return true если все финишировали
    static bool AllFinished(const std::vector<Swimmer*>& swimmers);

private:
    std::string name_;              ///< Имя пловца
    double speed_;                  ///< Скорость (м/с)
    double distance_;               ///< Текущее расстояние (м)
    double finishTime_;             ///< Время финиша (сек)
    bool finished_;                 ///< Флаг завершения
    mutable std::mutex dataMutex_;  ///< Мьютекс для защиты данных
};

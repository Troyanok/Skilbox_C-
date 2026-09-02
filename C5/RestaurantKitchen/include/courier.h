#pragma once

#include <thread>
#include <atomic>
#include <include/kitchen.h>

/// @brief Класс, представляющий курьера
class Courier
{
public:
    /// @brief Конструктор курьера
    /// @param kitchen Ссылка на кухню
    /// @param maxDeliveries Максимальное количество доставок
    Courier(Kitchen& kitchen, int maxDeliveries);

    /// @brief Запускает поток курьера
    void Start();

    /// @brief Ожидает завершения потока курьера
    void Join();

    /// @brief Проверяет, завершил ли курьер все доставки
    /// @return true если завершил
    bool IsFinished() const;

    /// @brief Возвращает количество выполненных доставок
    /// @return Количество доставок
    int GetDeliveredCount() const;

private:
    /// @brief Основной метод потока курьера
    void Run();

    Kitchen& kitchen_;
    int maxDeliveries_;
    std::atomic<int> deliveredCount_;
    std::atomic<bool> finished_;
    std::thread thread_;
};

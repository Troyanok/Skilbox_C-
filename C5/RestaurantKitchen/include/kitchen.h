#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <vector>
#include <include/order.h>

/// @brief Класс, представляющий кухню ресторана
class Kitchen
{
public:
    /// @brief Конструктор
    Kitchen();

    /// @brief Деструктор
    ~Kitchen();

    /// @brief Добавляет заказ в очередь
    /// @param dish Тип блюда
    void AddOrder(DishType dish);

    /// @brief Забирает готовое блюдо из очереди
    /// @param dish Ссылка для сохранения извлечённого блюда
    /// @return true если блюдо получено
    bool TakeReadyOrder(DishType& dish);

    /// @brief Проверяет, есть ли готовые блюда
    /// @return true если очередь не пуста
    bool HasReadyOrders() const;

    /// @brief Запускает поток кухни
    void Start();

    /// @brief Останавливает поток кухни
    void Stop();

private:
    /// @brief Основной цикл кухни
    void CookingLoop();

    std::queue<DishType> incomingOrders_;
    std::queue<DishType> readyOrders_;
    mutable std::mutex mtx_;
    std::condition_variable cvIncoming_;
    std::condition_variable cvReady_;
    bool cookingInProgress_;
    bool stopRequested_;
    std::thread cookingThread_;
};

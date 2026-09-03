#pragma once

#include <string>
#include <include/toy.h>

/// @brief Простой аналог std::shared_ptr для управления объектами Toy
class shared_ptr_toy
{
public:
    /// @brief Конструктор по умолчанию (пустой указатель)
    shared_ptr_toy();

    /// @brief Конструктор, создающий игрушку по имени
    /// @param name Имя игрушки
    explicit shared_ptr_toy(const std::string& name);

    /// @brief Конструктор копирования
    /// @param other Другой shared_ptr_toy
    shared_ptr_toy(const shared_ptr_toy& other);

    /// @brief Оператор присваивания
    /// @param other Другой shared_ptr_toy
    /// @return Ссылка на текущий объект
    shared_ptr_toy& operator=(const shared_ptr_toy& other);

    /// @brief Деструктор
    ~shared_ptr_toy();

    /// @brief Освобождает текущую ссылку
    void reset();

    /// @brief Возвращает сырой указатель на Toy
    /// @return Указатель или nullptr
    Toy* get() const;

    /// @brief Возвращает количество ссылок на Toy
    /// @return Количество ссылок или 0
    int use_count() const;

    /// @brief Возвращает имя игрушки или "Nothing"
    /// @return Имя
    std::string getToyName() const;

private:
    Toy* toy_;       ///< Указатель на игрушку
    int* refCount_;  ///< Указатель на счётчик ссылок

    /// @brief Вспомогательный метод освобождения
    void release();
};

/// @brief Фабричная функция
/// @param name Имя игрушки
/// @return shared_ptr_toy на новую игрушку
shared_ptr_toy make_shared_toy(const std::string& name);

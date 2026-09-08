#pragma once
#include <stdexcept>
#include <array>

/// @brief Исключение, выбрасываемое при пойманной рыбе
struct FishCaughtException : public std::exception
{
    const char* what() const noexcept override
  {
        return "Fish caught!";
    }
};

/// @brief Исключение, выбрасываемое при пойманном сапоге
struct BootCaughtException : public std::exception
{
    const char* what() const noexcept override
{
        return "Boot caught!";
    }
};

/// @brief Класс игрового поля для ловли рыбы
class FishingGame
{
public:
    /// @brief Конструктор. Случайно размещает рыбу и сапоги
    FishingGame();

    /// @brief Попытка забросить удочку в сектор
    /// @param sector Номер сектора (1-9)
    /// @throw FishCaughtException если поймана рыба
    /// @throw BootCaughtException если пойман сапог
    /// @throw std::invalid_argument если сектор вне диапазона
    void TryCatch(int sector);

private:
    enum class CellType
    {
        Empty,
        Fish,
        Boot
    };

    std::array<CellType, 9> field_;
};

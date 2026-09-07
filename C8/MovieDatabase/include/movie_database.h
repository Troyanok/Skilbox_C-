#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/// @brief Структура, представляющая актёра и роль.
struct ActorRole
{
    std::string actor;     ///< Имя актёра
    std::string character; ///< Роль
};

/// @brief Класс для загрузки и анализа базы фильмов из JSON.
class MovieDatabase
{
public:
    /// @brief Конструктор.
    /// @param jsonFilePath Путь к JSON-файлу.
    /// @throw std::runtime_error если файл не найден или некорректен.
    explicit MovieDatabase(const std::string& jsonFilePath);

    /// @brief Ищет актёра по имени или фамилии.
    /// @param searchQuery Строка поиска.
    /// @return Вектор пар: название фильма и роль.
    std::vector<std::pair<std::string, std::string>> SearchActor(const std::string& searchQuery) const;

private:
    json db_; ///< JSON-объект с данными
};

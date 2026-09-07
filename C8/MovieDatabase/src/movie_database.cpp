#include "include/movie_database.h"
#include <fstream>
#include <algorithm>
#include <cctype>

MovieDatabase::MovieDatabase(const std::string& jsonFilePath)
{
    std::ifstream file(jsonFilePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open JSON file: " + jsonFilePath);
    }
    file >> db_;
}

std::vector<std::pair<std::string, std::string>> MovieDatabase::SearchActor(const std::string& searchQuery) const
{
    std::vector<std::pair<std::string, std::string>> results;

    std::string queryLower = searchQuery;
    std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    for (auto it = db_.begin(); it != db_.end(); ++it)
    {
        const std::string& movieTitle = it.key();
        const auto& movieData = it.value();

        if (movieData.contains("cast") && movieData["cast"].is_array())
        {
            for (const auto& castEntry : movieData["cast"])
            {
                std::string actorName = castEntry.value("actor", "");
                std::string actorLower = actorName;
                std::transform(actorLower.begin(), actorLower.end(), actorLower.begin(),
                               [](unsigned char c) { return std::tolower(c); });

                if (actorLower.find(queryLower) != std::string::npos)
                {
                    std::string character = castEntry.value("character", "");
                    results.emplace_back(movieTitle, character);
                }
            }
        }
    }

    return results;
}

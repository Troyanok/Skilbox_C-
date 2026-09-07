#include <iostream>
#include <string>
#include <include/movie_database.h>

int main()
{
    try
      {
        MovieDatabase db("data/movies_db.json");

        std::cout << "Enter actor name or surname: ";
        std::string query;
        std::getline(std::cin, query);

        auto results = db.SearchActor(query);

        if (results.empty())
        {
            std::cout << "No actors found matching \"" << query << "\"." << std::endl;
        }
        else
        {
            std::cout << "Found in following movies: " << std::endl;
            for (const auto& [movie, role] : results)
            {
                std::cout << "- " << movie << " as " << role << std::endl;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

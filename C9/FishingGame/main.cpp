#include <iostream>
#include "include/fishing_game.h"

int main()
{
    FishingGame game;
    int attempts = 0;
    std::cout << "Welcome to the fishing game! There are 9 sectors." << std::endl;

    while (true)
    {
        std::cout << "Enter sector (1-9): ";
        int sector;
        std::cin >> sector;
        attempts++;
        try
        {
            game.TryCatch(sector);
            std::cout << "Empty sector, try again." << std::endl;
        }
        catch(const FishCaughtException& e)
        {
            std::cout << "Congratulations! " << e.what() << " in " << attempts << " attempts." << std::endl;
            break;
        }
        catch (const BootCaughtException& e)
        {
            std::cout << "Oops! " << e.what() << " Game over after " << attempts << " attempts." << std::endl;
            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}

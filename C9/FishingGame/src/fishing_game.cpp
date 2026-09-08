#include "include/fishing_game.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

FishingGame::FishingGame()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    field_.fill(CellType::Empty);

    int fishPos = std::rand() % 9;
    field_[fishPos] = CellType::Fish;

    int bootsPlaced = 0;
    while (bootsPlaced < 3)
    {
        int pos = std::rand() % 9;
        if (field_[pos] == CellType::Empty)
        {
            field_[pos] = CellType::Boot;
            ++bootsPlaced;
        }
    }
}

void FishingGame::TryCatch(int sector)
{
    if ((sector < 1) || (sector > 9))
    {
        throw std::invalid_argument("Sector number must be between 1 and 9");
    }
    int index = sector - 1;
  
    switch (field_[index])
    {
        case CellType::Fish:
        {
            throw FishCaughtException();
        }
        case CellType::Boot:
        {
            throw BootCaughtException();
        }
        default:
        {
            break;
        }
    }
}

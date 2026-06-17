#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string picturePath;
    std::cout << "Введите путь к картинке: ";
    std::cin >> picturePath;

    std::ifstream pngFile(picturePath, std::ios::binary);
    if (!pngFile.is_open())
    {
        std::cout << "Failed to open file: " << picturePath << std::endl;
        return -1;
    }

    char buffer[4];
    pngFile.read(buffer, sizeof(buffer));
    
    if (pngFile.gcount() != sizeof(buffer))
    {
        std::cout << "Входной файл не является PNG (слишком короткий)" << std::endl;
        return 0;
    }

    bool isPNG = (static_cast<unsigned char>(buffer[0]) == 0x89) &&
                 (buffer[1] == 'P') &&
                 (buffer[2] == 'N') &&
                 (buffer[3] == 'G');

    if (isPNG)
    {
        std::cout << "Входной файл является PNG-изображением" << std::endl;
    }
    else
    {
        std::cout << "Входной файл не является PNG-изображением" << std::endl;
    }

    return 0;
}

#include <include/audio_player.h>

#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Добро пожаловать в аудиоплеер. Введите название файла для получения плейлиста: ";
    std::cin >> fileName;
    AudioPlayer player(fileName);

    std::string command;
    while (1)
    {
        std::cout << "Введите команду:" << std::endl
                  << "  play  - Воспроизвести трек" << std::endl
                  << "  pause - Поставить на паузу" << std::endl
                  << "  next  - Следующий трек (shuffle)" << std::endl
                  << "  stop  - Остановить" << std::endl
                  << "  exit  - Выйти" << std::endl
                  << ">> ";
        std::cin >> command;
        std::cin.ignore();

        if (command == "exit")
        {
            std::cout << "Завершение работы плеера." << std::endl;
            break;
        }
        else if (command == "play")
        {
            std::string trackName;
            std::cout << "Введите название трека: ";
            std::getline(std::cin, trackName);
            player.PlayTrack(trackName);
        }
        else if (command == "pause")
        {
            player.PauseTrack();
        }
        else if (command == "stop")
        {
            player.StopTrack();
        }
        else if (command == "next")
        {
            player.NextTrack();
        }
        else
        {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }

        std::cout << std::endl;
    }
    return 0;
}

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
    while (true)
    {
        std::cout << "\nВведите команду:\n"
                  << "  play  - Воспроизвести трек\n"
                  << "  pause - Поставить на паузу\n"
                  << "  next  - Следующий трек (shuffle)\n"
                  << "  stop  - Остановить\n"
                  << "  exit  - Выйти\n"
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
    }
    return 0;
}

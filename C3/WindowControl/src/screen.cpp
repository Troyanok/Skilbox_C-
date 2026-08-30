#include <include/screen.h>
#include <include/constants.h>

void Screen::GetUserWindowParams()
{
    int x, y, w, h;
    while (true)
    {
        std::cout << "Введите начальные координаты (x y) и размеры (ширина высота) окна: ";
        std::cin >> x >> y >> w >> h;

        if ((w <= 0) || (h <= 0))
        {
            std::cout << "Ширина и высота должны быть положительными. Повторите: ";
            std::cout << std::endl;
            continue;
        }
        if ((x < 0) || (y < 0) || (x + w > window_size::WindowWidth) || (y + h > window_size::WindowHeight))
        {
            std::cout << "Окно выходит за границы экрана. Повторите: ";
            std::cout << std::endl;
            continue;
        }
        break;
    }

    userWin_ = Window(x, y, w, h);
    std::cout << std::endl;
}

void Screen::WorkScreenCommand()
{
    std::string command;

    std::cout << "Добро пожаловать в симулятор управления окна рабочего стола!" << std::endl;

    while(1)
    {
        std::cout << "Введите команду: " << std::endl
                  << "\t move - Сместить окно на экране" << std::endl
                  << "\t resize - Изменить размер окна на экране" << std::endl
                  << "\t display - Вывессти текущее изображение монитора в консоль. 0 - пиксель вне области, 1 - с окном" << std::endl
                  << "\t close - завершить работу приложения" << std::endl
                  << ">> ";
        std::cin >> command;
        std::cin.ignore();

        if (command == "close")
        {
            std::cout << "Завершение работы симулятор управления окна рабочего стола" << std::endl;
            break;
        }
        else if (command == "move")
        {
            int dx, dy;
            std::cout << "Введите новые координаты для смещения окна: ";
            std::cin >> dx >> dy;

            if (userWin_.MoveWindow(dx, dy))
            {
                std::cout << "Новые координаты окна: (" << userWin_.GetX() << ", " << userWin_.GetY() << ")" << std::endl;
            }
            else
            {
                std::cout << "Не удалось сдвинуть окно: оно выйдет за границы экрана." << std::endl;
            }
        }
        else if (command == "resize")
        {
            int newW, newH;
            std::cout << "Введите новые ширину и высоту: ";
            std::cin >> newW >> newH;

            if (userWin_.ResizeWindow(newW, newH))
                std::cout << "Новый размер окна: " << userWin_.GetWidth() << "x" << userWin_.GetHeight() << std::endl;
            else
                std::cout << "Не удалось изменить размер. Проверьте положительность и вписываемость в экран." << std::endl;
        }
        else if (command == "display")
        {
            PrintDisplay();
        }
        else
        {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }
        std::cout << std::endl;
    }
}

void Screen::PrintDisplay()
{
    int x = userWin_.GetX();
    int y = userWin_.GetY();
    int w = userWin_.GetWidth();
    int h = userWin_.GetHeight();

    for (int row = 0; row < window_size::WindowHeight; ++row)
    {
        for (int col = 0; col < window_size::WindowWidth; ++col)
        {
            if (col >= x && col < x + w && row >= y && row < y + h)
            {
                std::cout << '1';
            }
            else
            {
                std::cout << '0';
            }
        }
        std::cout << std::endl;
    }
}

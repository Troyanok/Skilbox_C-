#include <include/window.h>
#include <include/constants.h>

namespace
{

/// @brief Проверить, расположено ли окно внутри экрана или нет
/// @param x Начальная координата OX
/// @param y Начальная координата OY
/// @param w Высота окна
/// @param h Ширина окна
/// @return true - окно внутри экрана, иначе - false
bool CheckInsideScreen(int x, int y, int w, int h)
{
    return x >= 0 && y >= 0 &&
           (x + w <= window_size::WindowWidth) &&
           (y + h <= window_size::WindowHeight);
}

}

Window::Window()
    : x_(0)
    , y_(0)
    , width_(0)
    , height_(0)
{}

Window::Window(int x, int y, int width, int height)
    : x_(x)
    , y_(y)
    , width_(width)
    , height_(height)
{}

bool Window::MoveWindow(int dx, int dy)
{
    int newX = x_ + dx;
    int newY = y_ + dy;
    if (CheckInsideScreen(newX, newY, width_, height_))
    {
        x_ = newX;
        y_ = newY;
        return true;
    }
    return false;
}

bool Window::ResizeWindow(int newWidth, int newHeight)
{
    if ((newWidth <= 0) || (newHeight <= 0))
    {
        return false;
    }

    if (CheckInsideScreen(x_, y_, newWidth, newHeight))
    {
        width_ = newWidth;
        height_ = newHeight;
        return true;
    }
    return false;
}

int Window::GetX() const
{
    return x_;
}

int Window::GetY() const
{
    return y_;
}

int Window::GetWidth() const
{
    return width_;
}

int Window::GetHeight() const
{
    return height_;
}

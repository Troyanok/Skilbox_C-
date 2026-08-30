#include <include/surgery_tools.h>

namespace surgery_tools
{

Point::Point()
    : x(0)
    , y(0)
{};

void InputPoint(Point& curPoint)
{
    std::cout << "Введите координату X: ";
    std::cin >> curPoint.x;
    std::cout << "Введите координату Y: ";
    std::cin >> curPoint.y;
}

bool CheckEqualPoints(const Point& first, const Point& second)
{
    return (first.x == second.x) && (first.y == second.y);
}

void ScalpelAction(const Point &first, const Point& second)
{
    std::cout << "Выполнен разрез между точками ";
    PrintPoint(first);
    std::cout << " и ";
    PrintPoint(second);
    std::cout << std::endl;
}

void HemostatAction(const Point& currentPoint)
{
    std::cout << "Зажим установлен в точке ";
    PrintPoint(currentPoint);
    std::cout << std::endl;
}

void TweezersAction(const Point& currentPoint)
{
    std::cout << "Пинцет установлен в точке ";
    PrintPoint(currentPoint);
    std::cout << std::endl;
}

void SutureAction(const Point& first, const Point& second)
{
    std::cout << "Установить шов между точками ";
    PrintPoint(first);
    std::cout << " и ";
    PrintPoint(second);
    std::cout << std::endl;
}

void PrintPoint(const Point& currentPoint)
{
    std::cout << "(" << currentPoint.x << ", " << currentPoint.y << ")";
}

}

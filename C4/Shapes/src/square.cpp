#include <include/square.h>
#include <stdexcept>

Square::Square(double centerX, double centerY, double side, Color color)
    : Figure(centerX, centerY, color)
    , side_(side)
{
    if (side <= 0.0) 
    {
        throw std::invalid_argument("Side must be positive");
    }
}

double Square::GetArea() const
{
    return side_ * side_;
}

BoundingBox Square::GetDescribingRectangle() const
{
    return {centerX_ - side_ / 2.0, centerY_ - side_ / 2.0, side_, side_};
}
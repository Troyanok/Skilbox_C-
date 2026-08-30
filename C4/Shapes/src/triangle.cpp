#include <include/triangle.h>
#include <cmath>
#include <stdexcept>

EquilateralTriangle::EquilateralTriangle(double centerX, double centerY, double side, Color color)
    : Figure(centerX, centerY, color)
    , side_(side)
{
    if (side <= 0.0)
    {
        throw std::invalid_argument("Side must be positive");
    }
}

double EquilateralTriangle::GetArea() const
{
    return side_ * side_ * std::sqrt(3.0) / 4.0;
}

BoundingBox EquilateralTriangle::GetDescribingRectangle() const
{
    double height = side_ * std::sqrt(3.0) / 2.0;
    return {centerX_ - side_ / 2.0, centerY_ - height / 2.0, side_, height};
}
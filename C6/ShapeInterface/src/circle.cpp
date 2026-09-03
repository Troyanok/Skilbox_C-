#include <include/circle.h>
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) : radius_(radius)
{
    if (radius_ <= 0.0)
    {
        throw std::invalid_argument("Radius must be positive");
    }
}

double Circle::Square() const
{
    return std::atan(1.0) * 4.0 * radius_ * radius_;
}

BoundingBoxDimensions Circle::Dimensions() const
{
    double diameter = 2.0 * radius_;
    return {diameter, diameter};
}

std::string Circle::Type() const
{
    return "Circle";
}

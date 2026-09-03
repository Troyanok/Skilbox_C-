#include <include/triangle.h>
#include <cmath>
#include <stdexcept>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : a_(sideA)
    , b_(sideB)
    , c_(sideC)
{
    if ((a_ + b_ <= c_) || (a_ + c_ <= b_) || (b_ + c_ <= a_))
    {
        throw std::invalid_argument("Invalid triangle sides");
    }
}

double Triangle::Square() const
{
    double p = (a_ + b_ + c_) / 2.0;
    return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
}

BoundingBoxDimensions Triangle::Dimensions() const
{
    double area = Square();
    double radius = (a_ * b_ * c_) / (4.0 * area);
    double side = 2.0 * radius;
    return {side, side};
}

std::string Triangle::Type() const
{
    return "Triangle";
}

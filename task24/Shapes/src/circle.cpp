#include <include/circle.h>
#include <cmath>

Circle::Circle(double centerX, double centerY, double radius, Color color)
    : Figure(centerX, centerY, color)
    , radius_(radius)
{
    if (radius <= 0.0)
    {
        throw std::invalid_argument("Radius must be positive");
    }
}

double Circle::GetArea() const
{
    return std::atan(1.0) * 4.0 * radius_ * radius_;
}

BoundingBox Circle::GetDescribingRectangle() const 
{
    double diameter = 2.0 * radius_;
    return {centerX_ - radius_, centerY_ - radius_, diameter, diameter};
}
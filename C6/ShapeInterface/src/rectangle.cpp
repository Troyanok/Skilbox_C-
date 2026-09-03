#include <include/rectangle.h>
#include <stdexcept>

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height)
{
    if ((width_ <= 0.0) || (height_ <= 0.0))
    {
        throw std::invalid_argument("Width and height must be positive");
    }
}

double Rectangle::Square() const
{
    return width_ * height_;
}

BoundingBoxDimensions Rectangle::Dimensions() const
{
    return {width_, height_};
}

std::string Rectangle::Type() const
{
    return "Rectangle";
}

#include <include/rectangle.h>
#include <stdexcept>

RectangleFigure::RectangleFigure(double centerX, double centerY, double width, double height, Color color)
    : Figure(centerX, centerY, color), width_(width)
    , height_(height)
{
    if ((width <= 0.0) || (height <= 0.0))
    {
        throw std::invalid_argument("Width and height must be positive");
    }
}

double RectangleFigure::GetArea() const
{
    return width_ * height_;
}

BoundingBox RectangleFigure::GetDescribingRectangle() const
{
    return {centerX_ - width_ / 2.0, centerY_ - height_ / 2.0, width_, height_};
}
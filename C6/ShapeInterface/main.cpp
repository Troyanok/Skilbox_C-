#include <iostream>
#include <include/shape.h>
#include <include/circle.h>
#include <include/rectangle.h>
#include <include/triangle.h>

/// @brief Выводит параметры фигуры
/// @param shape Указатель на фигуру
void printParams(Shape* shape)
{
    BoundingBoxDimensions dims = shape->Dimensions();
    std::cout << "Type: " << shape->Type() << std::endl;
    std::cout << "Square: " << shape->Square() << std::endl;
    std::cout << "Width: " << dims.width << std::endl;
    std::cout << "Height: " << dims.height << std::endl;
    std::cout << std::endl;
}

int main()
{
    try
    {
        Circle circle(5.0);
        Rectangle rectangle(3.0, 4.0);
        Triangle triangle(3.0, 4.0, 5.0);

        printParams(&circle);
        printParams(&rectangle);
        printParams(&triangle);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

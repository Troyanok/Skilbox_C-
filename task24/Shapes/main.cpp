#include <iostream>
#include <memory>
#include <string>
#include <include/circle.h>
#include <include/square.h>
#include <include/triangle.h>
#include <include/rectangle.h>

int main()
{
    std::cout << "Geometric Shapes" << std::endl;
    while (true)
    {
        std::string command;
        std::cout << "Enter command (circle/square/triangle/rectangle/exit): ";
        std::cin >> command;
        if (command == "exit")
        {
            break;
        }

        double cx, cy, param1, param2 = 0.0;
        std::string colorStr;
        std::cout << "Center X, Center Y, ";
        if (command == "circle")
        {
            std::cout << "Radius, Color(red/blue/green/none): ";
            std::cin >> cx >> cy >> param1 >> colorStr;
        }
        else if (command == "square" || command == "triangle")
        {
            std::cout << "Side, Color(red/blue/green/none): ";
            std::cin >> cx >> cy >> param1 >> colorStr;
        }
        else if (command == "rectangle")
        {
            std::cout << "Width, Height, Color(red/blue/green/none): ";
            std::cin >> cx >> cy >> param1 >> param2 >> colorStr;
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
            continue;
        }

        Color color = Color::None;
        if (colorStr == "red")
        {
            color = Color::Red;
        }
        else if (colorStr == "blue")
        {
            color = Color::Blue;
        }
        else if (colorStr == "green")
        {
            color = Color::Green;
        }

        try
        {
            std::unique_ptr<Figure> fig;
            if (command == "circle")
            {
                fig = std::make_unique<Circle>(cx, cy, param1, color);
            }
            else if (command == "square")
            {
                fig = std::make_unique<Square>(cx, cy, param1, color);
            }
            else if (command == "triangle")
            {
                fig = std::make_unique<EquilateralTriangle>(cx, cy, param1, color);
            }
            else if (command == "rectangle")
            {
                fig = std::make_unique<RectangleFigure>(cx, cy, param1, param2, color);
            }

            BoundingBox bb = fig->GetDescribingRectangle();
            std::cout << "Area: " << fig->GetArea() << "" << std::endl;
            std::cout << "Describing rectangle: x=" << bb.x << " y=" << bb.y
                      << " width=" << bb.width << " height=" << bb.height << "" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << "" << std::endl;
        }
    }
    return 0;
}

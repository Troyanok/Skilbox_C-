#include <iostream>

#pragma once

namespace surgery_tools
{

struct Point
{
    double x;
    double y;

    Point();
};

void InputPoint(Point& curPoint);

bool CheckEqualPoints(const Point& first, const Point& second);

void scalpel(const Point& first, const Point& second);

void hemostat(const Point& currentPoint);

void tweezers(const Point& currentPoint);

void suture(const Point& first, const Point& second);

void PrintPoint(const Point& currentPoint);

}

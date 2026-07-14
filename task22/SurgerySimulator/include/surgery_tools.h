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

void ScalpelAction(const Point& first, const Point& second);

void HemostatAction(const Point& currentPoint);

void TweezersAction(const Point& currentPoint);

void SutureAction(const Point& first, const Point& second);

void PrintPoint(const Point& currentPoint);

}

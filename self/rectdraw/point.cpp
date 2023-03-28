#include <iostream>
#include <string>
#include "point.hpp"

Point::Point()
{
    _x = 0;
    _y = 0;
}

Point::Point(int x, int y)
{
    _x = x;
    _y = y;
}

void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}

int Point::x() const 
{
    return _x;
}

int Point::y() const 
{
    return _y;
}
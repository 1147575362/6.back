#include <iostream>
#include <string>
#include "point.hpp"
#include "rect.hpp"
using namespace std;

Rect::Rect(int w, int h)
{
    _width = w;
    _height = h;
}

Rect::Rect(int w, int h, Point pos) : _width(w), _height(h), _pos(pos) {}

Rect::Rect(int w, int h, int x, int y) : _pos(x, y)
{
    _width = w;
    _height = h;
}

void Rect::set_width(int w)
{
    Rect::_width = w;
}

void Rect::set_height(int h)
{
    if (h < 0)
    {
        cout << "height must be greater than 0!" << endl;
    }
    Rect::_height = h;
}

int Rect::get_width() const
{
    return _width;
}

int Rect::get_height() const
{
    return _height;
}

int Rect::area() const
{
    return Rect::_height * Rect::_width;
}

void Rect::draw(Lcd &lcd, Color color)
{
    for (int i = 0; i < _height; i++)
        for (int j = 0; j < _width; j++)
            lcd.drawPoint(j, i, color);
}
#ifndef RECT_HPP_
#define RECT_HPP_

#include "point.hpp"
#include "color.hpp"
#include "lcd.hpp"

class Rect
{
public:
    Rect(int w, int h);
    Rect(int w, int h, int x, int y);
    Rect(int w, int h, Point pos);

    void set_width(int w);
    void set_height(int h);
    int get_width() const;
    int get_height() const;
    int area() const;
    void draw(Lcd &lcd, Color color);

private:
    int _width;
    int _height;
    Point _pos;
};

#endif
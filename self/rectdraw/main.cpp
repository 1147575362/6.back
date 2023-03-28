#include <iostream>
#include <string>
#include "color.hpp"
#include "lcd.hpp"
#include "point.hpp"
#include "rect.hpp"

int main()
{
    Lcd lcd("/dev/fb0");
    lcd.drawPoint(100,100,Color(255,255,255));

    Rect r(800,480);
    r.draw(lcd,Color(0,0,0));
    return 0;
}
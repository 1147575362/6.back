#ifndef LCD_HPP
#define LCD_HPP

#include "color.hpp"
#include <string>
class Lcd
{
public:
    Lcd(std::string name);
    ~Lcd();

    void drawPoint(int x, int y, Color color);

private:
    // std::string _name;
    int _fd;    // 文件描述符
    int *_addr; // 映射地址
    int _width;
    int _height;
    int _bpp; // 位深
};


#endif
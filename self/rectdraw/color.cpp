#include <iostream>
#include <string>
#include "color.hpp"

// 在hpp里用列表定义了构造函数初值，还要在cpp里定义吗？  必须在cpp里定义列表初值
// Color::Color(int r, int g, int b):_red(r),_green(g),_blue(b)
// {

// }
Color::Color(int r, int g, int b): _red(r), _green(g), _blue(b)
{
}

int Color::value() const
{

    int v = _red << 16 | _green << 8 | _blue;
    return v;
}
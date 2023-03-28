// 用class描述矩形

#include <iostream>
#include <string>
using namespace std;

class Rect
{
public:
    int area() const;
    void set_width(int w);
    void set_height(int h);
    int get_width();
    int get_height();

private:
    int _width;
    int _height;
};

void Rect::set_width(int w) // 类外定义成员函数，需要指明作用域，如Rect::
{
    _width = w;
}

void Rect::set_height(int h)
{
    _height = h;
}

int Rect::get_height()
{
    return _height;
}

int Rect::get_width()
{
    return _width;
}

int Rect::area() const  //对于类的成员函数，如果该函数保证不修改对象的状态，则一般建议设置为const函数
{
    return _height * _width;
}

int main()
{
    Rect r;
    r.set_width(10);
    r.set_height(5);
    cout << r.get_width() << endl;
    cout << r.get_height() << endl;
    cout << r.area() << endl;
}
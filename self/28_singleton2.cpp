//延时初始化(饱汉模式)

#include "singleton2.hpp"
#include <iostream>
using namespace std;

singleton2& singleton2::get_s()
{
    static singleton2 s(200);   //static变量可以在static函数里面直接声明定义
    return s;

}

singleton2::singleton2(int value):x(value)
{
    cout << "构造函数" << endl;
}

int singleton2::get_value() const
{
    return this->x;
}

int main(int argc, char const *argv[])
{
    singleton2 &s1 =  singleton2::get_s();
    cout << s1.get_value() << " , " << &s1 << endl;

    singleton2 &s2 =  singleton2::get_s();
    cout << s2.get_value() << " , " << &s2 << endl;
    return 0;
}

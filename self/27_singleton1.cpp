//单例模式
//预先初始化(饿汉模式)

#include "singleton1.hpp"
#include <iostream>
using namespace std;

singleton singleton::s(100);    //s的类型 s的作用域::s(要赋的值)

singleton& singleton::get_s()
{
    return s;
}

singleton::singleton(int value):x(value)
{
    cout << "构造函数" << endl;
}

int singleton::get_value() const
{
    return this->x;
}


int main(int argc, char const *argv[])
{
    // singleton s(100); 
    //因为把构造函数写进了private，其禁止了用户实例化对象，需要调用静态成员接口才能实现。

    singleton &s1 = singleton::get_s();
    cout << s1.get_value() << " , " << &s1 << endl; 

    singleton &s2 = singleton::get_s();
    cout << s2.get_value() << " , " << &s2 << endl; 
    //这里创建一个引用接受get_s()返回创建的对象，
    //无论用户调用多少次这个静态成员接口，返回的对象都是同一个。
    return 0;
}


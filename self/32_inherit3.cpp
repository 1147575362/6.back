
// 派生类对象和基类对象之间的关系
#include <iostream>
using namespace std;

class Bases
{
protected:
    

public:
    Bases(/* args */) = default;
    int x1 = 123;
};

class Derived : public Bases
{
protected:
    

public:
    Derived(/* args */) = default;
    int y1 = 456;
};

int main(int argc, char const *argv[])
{
    Derived d;
    Bases b;
    // Bases &b = d;       //基类引用可以绑定到任意派生类对象。
    // b = d;         //用派生类对象赋值给基类对象
    // Bases b(d); // 用派生类对象初始化基类对象
    Bases *b = &d;
    // cout << b.y1 << endl;
    return 0;
}

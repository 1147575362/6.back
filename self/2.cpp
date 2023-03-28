#include <iostream>
using namespace std;

union A
{
    int a = 2;
    char b;
};

A a;
A b;


struct SB{
    int sb = 10;
    int fw[3] = {1,2,3};
    void f1()
    {
    cout << "wssb" << endl;
    };

}sb;



enum Color {RED=0xff0000, GREEN=0x00ff00, BLUE=0x0000ff};

int main()
{
    Color color = Color::RED;   //Color定义的color实例只能在RED GREEN BLUE里面选
    cout << color <<endl;
    cout << "----------" << endl;
    sb.f1();
    cout << sb.fw[2] << endl;
    cout << sb.sb << endl;
};
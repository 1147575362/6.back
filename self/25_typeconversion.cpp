#include <iostream>
using namespace std;

class Demo
{
private:
    int _x;
    char _c;
public:
    Demo(int x = 0,int c = 'q'):_x(x),_c(c){}
    operator int() const    //运算符类型转换函数
    {
        return _x;
    }
        operator char() const    //运算符类型转换函数
    {
        return _c;
    }
};

int main(int argc, char const *argv[])
{
    Demo d{40,'g'};
    int a = d;      //直接将d的int成员变量赋给a
    char b = d;     //直接将d的char成员变量赋给b
    cout << a << endl;
    cout << b << endl;
    return 0;
}

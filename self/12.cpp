// 析构函数

#include <iostream>
#include <string>
using namespace std;

class Demo
{
public:
    Demo(int a, int b) : _value(a), _p(b)
    {
        cout << "gouzao" << endl;
    }
    ~Demo()
    {
        _value = 0;
        _p = 0;
        cout << "xigou " << endl;
    }

    int value() const;
    int p() const;

private:
    int _value;
    int _p;
};

int Demo::p() const
{
    return Demo::_p;
}

int Demo::value() const
{
    return Demo::_value;
}

void print(const Demo &t)
{
    cout << t.value() << "," << t.p() << endl;
}

int main()
{   
    Demo a(10,20);
    print(a);
}
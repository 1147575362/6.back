#include <iostream>
using namespace std;

class Demo
{
private:
    int *p;

public:
    Demo(int x = 0)
    {
        p = new int(x);
    }
    ~Demo()
    {
        delete p;
        p = nullptr;
    }

    //拷贝赋值运算符函数
    Demo& operator=(const Demo& other)
    {
        *p = *(other.p);
        cout << "拷贝赋值运算符函数" << endl;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Demo &x)
    {
        return out << x.p << ", " << *x.p;
    }
};

int main(int argc, char const *argv[])
{
    Demo a(500);
    Demo b;
    b = a;
    cout << a << endl;
    cout << b << endl;
    return 0;
}

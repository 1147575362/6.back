#include <iostream>
#include <string>
using namespace std;


class Demo
{
private:
    int *p;
public:
    Demo()
    {
        cout << "gouzao" << endl;
        p = new int[10];
    }

    // Demo(const Demo& other) //自定义拷贝构造函数
    // {
    //     cout << "自定义拷贝构造函数" <<endl;
    //     other.p = new int;
    //     other.p = this->p;
    // }
    ~Demo()
    {
        cout << "xigou" << endl;
        delete p;
        p = nullptr;
    }

    void set_p()
    {
        *this->p = 10;
    }
    
    void set_p(Demo *x) // 指针和引用都不会创建新对象
    {
        *(x->p) = 20;
        x->print();
        this->print();
    }

    void print()
    {
        cout << *p << endl;
    }
};

int main(int argc, char const *argv[])
{
    Demo a;
    a.set_p();
    a.print();
    cout << "------" << endl;
    a.set_p(&a);
    a.print();
    return 0;
}

#include <iostream>
using namespace std;

void swap1(int &c, int &d) // 引用就是把这个变量的地址给复制一份？
{
    int t = c;
    c = d;
    d = t;
}

void swap2(int *c, int *d)
{
    int t = *c;
    *c = *d;
    *d = t;
}

    void bar(const int& r)  //const指定了常量，不能变
    {
        //r++; // error
    }


void foo1(int &x)
{
    x++;
}

int& foo2(int &x)
{
    x++;
    return x;
}

// void print(a,b)
// {
//     std::cout << a << b << std::endl;
// }

int main()
{
    int a = 1;
    int &r = a;
    cout << &a << endl; //&a就是a的一个地址,&r就是把地址复制一份
    cout << &r << endl;
    cout << r << endl;

    // cout << "------------------" << endl;
    // r++;
    // cout << a << endl;
    // cout << r << endl;
    // cout << "------------------" << endl;

    // foo1(r);
    // cout << r << endl;
    // foo2(r);
    // cout << r << endl;

    // int a = 10;
    // int b = 20;
    // swap2(&a,&b);
    // cout << a << "," << b << endl;
}
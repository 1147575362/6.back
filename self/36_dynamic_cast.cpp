// 动态类型的转换

#include <iostream>
using namespace std;

class shape // 纯虚函数
{
public:
    virtual double area() = 0;
};

class yuan : public shape
{
private:
public:
    double area() override
    {
        return 10;
    }
    double pa()
    {
        return 3.14;
    }
};

class juxing : public shape
{
private:
public:
    double area() override
    {
        return 20;
    }
};

void foo(shape *ps)
{
    cout << ps->area() << endl;
}

int main(int argc, char const *argv[])
{
    yuan a1;
    juxing a2;
    shape *s[2] = {&a1, &a2}; // 把形状这个抽象基类派生下来的派生类对象都放进一个数组里，统一操作一个接口

    for (int i = 0; i < 2; i++)
    {
        yuan *pc = dynamic_cast<yuan *>(s[i]);  
        //s[i]里有两个指针：第一个指向圆类，第二个指向矩形类。
        //将第一个的圆类指针转成圆类，自然转换成功，返回地址；
        //将第二个矩形类指针转成圆类，不行，返回nullptr。
        //用这个来方法分辨在抽象类下是否有新添加接口的派生类并使用这个新添加的接口
        if (pc != nullptr)
        {
            cout << pc->pa() << endl;
        }

        // foo(s[i]);
    }
    return 0;
}

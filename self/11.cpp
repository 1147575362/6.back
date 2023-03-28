//成员初始化列表
//     构造函数名(参数列表): 成员1(初值), ..., 成员n(初值)
//     {
//         函数体
//     }
#include <iostream>
using namespace std;


// A类型没有默认构造函数
class A 
{
public:
    A(int a): _a(a) {}
private:
    int _a;
};



class Demo
{
public:
    Demo(int value): c(a), a(value), r(a) {}
    
    int getValue() const 
    {
        return a;
    }
    int getRef() const 
    {
        return r;
    }
private:
    const int a;    //成员是常量必须要用初始化列表
    const int& r;   //成员是引用必须要用初始化列表
    A c;            //成员是其他类型的对象必须要用初始化列表
};



int main(int argc, char const *argv[])
{
    Demo d(100);    //100作value传入
    cout << d.getValue() << endl;
    cout << d.getRef() << endl;
    return 0;
}

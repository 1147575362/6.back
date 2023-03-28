// 默认参数

#include <iostream>
#include <string>
using namespace std;

void sum(int, int b = 3); // 若提前声明，则默认值得写在这里

void sum(int a, int b)  // 若某个形参设置了默认值，则在其右边的每个参数都得设定默认值
{
    cout << a + b << endl;
}

int main()
{
    sum(1); //在这里调用只需写上没有默认的实参
    // sum(1,5)  //若在这里重写，则覆盖掉默认值
    return 0;
}
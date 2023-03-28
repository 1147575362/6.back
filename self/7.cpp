//extern "c"关键字称为链接指示，用于告诉C++编译器，按照C语言的规则去链接指定的函数

#include <iostream>
using namespace std;

int sub(int a, int b);//c++声明

#ifdef __cplusplus  //c声明 
extern "C"
{
#endif

    int sub_c(int, int);

#ifdef __cplusplus
}
#endif

int sub(int a, int b)
{
    return a + b;
}

int sub_c(int a, int b)
{
    return a + b;
}

int main()
{
    cout << sub(2, 3) << endl;
    cout << sub_c(3, 10) << endl;
}

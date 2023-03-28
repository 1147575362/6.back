// 异常抛出与处理

#include <iostream>
using namespace std;

// void foo(int a)
// {
//     if(a < 10)
//         throw("sb");
// }

// void bar()
// {
//     foo(2);
// }

// void f1()
// {
//     throw(2);
// }

// int main()
// {
//     try
//     {
//         bar();
//         f1();   //第一句被捕获到，try中后面的语句就不会执行了
//     }
//     catch(const char* e)
//     {
//         cout << "字符串类型的异常" << endl;
//     }

//     catch(int e)
//     {
//         cout << "整数类型的异常" << endl;
//     }
//     return 0;
// }

// 用C++标准库提供的异常类型

//1.在main里找不到catch，由os处理异常，结束进程
void foo()  
{
    
    throw std::runtime_error("程序运行异常");
    
}

int main()
{
    cout << "start" << endl;
    foo();
    cout << "end" << endl;
    return 0;
}

//2.在main里的catch是一个类型，定义一个e实体，用e的what()方法打印异常
// void foo()
// {
//     throw std::runtime_error("程序运行异常");
// }

// int main()
// {
//     try
//     {
//         foo();
//     }
//     catch (runtime_error e)
//     {
//         cout << e.what() << endl;
//     }

//     return 0;
// }
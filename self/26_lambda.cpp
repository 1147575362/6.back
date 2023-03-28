#include <iostream>
using namespace std;

// class Demo
// {
// private:
//     /* data */
// public:
//     Demo(/* args */);

// };
void print(int a[], int n, auto f1)
{
    for (int i = 0; i < n; i++)
        f1(a[i]);
}
int main(int argc, char const *argv[])
{
    // 用法一：给lambda命名，类型自动，再调用lambda
    //  int a = 10;
    //  int b = 20;
    //&表示捕获该函数内所有局部变量的引用(能修改)，=表示捕获该函数内所有局部变量的值
    // 或者在里面写a,b
    //()里面可以自定义变量
    //  auto f = [&]()
    //  {
    //      cout << a << ", " << b << endl;
    //      a = 1;
    //      b = 2;
    //      cout << a << ", " << b << endl;
    //  };
    //  f();

    // 用法二：lambda做函数参数传入 (结合上面的print函数)

    int arr[3] = {10, 20, 30};
    print(arr, 3, [](int x)
          { cout << oct << x << ", "; });
    cout << endl;

    return 0;
}

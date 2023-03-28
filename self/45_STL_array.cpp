#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    // 成员函数
    array<int, 4> a = {5, 3, 1, 4};
    cout << a.at(2) << endl;
    cout << a[3] << endl;
    cout << a.front() << endl;
    cout << a.data() << endl; // 首地址

    // 迭代器
    cout << a.begin() << endl; // 首地址

    a.at(4) = 666;

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
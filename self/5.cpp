// 字符串题目
#include <iostream>
#include <string>
#include <fcntl.h>
#include <stdio.h>
using namespace std;

int foo()
{
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    string s1;
    cin >> s1;
    cout << s1 << endl;
    if (s1.length() >= 6)
        flag1 = 1;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1.at(i) > '0' && s1.at(i) < '9')
            flag2 = 1;
        if (s1.at(i) >= 'a' && s1.at(i) <= 'z')
            flag3 = 1;
        if (s1.at(i) >= 'A' && s1.at(i) <= 'Z')
            flag4 = 1;
    }
    cout << flag1 << "," << flag2 << "," << flag3 << "," << flag4 << endl;
    if (flag1 && flag2 && flag3 && flag4)
        return 1;
    else
        return 0;
}

int main()
{
    int a = foo();
    cout << a << endl;
    return 0;
}
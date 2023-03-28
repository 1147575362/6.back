//函数重载
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void f1(int a,int b)
{
    cout << pow(a,b) << endl; //a的b次方
}

void f1()
{
    cout << "sb" << endl;   
}

int f1(string s1,string s2)
{
    cout << s1 + s2 << endl;
    if(s1 == s2)
        return 1;
    else
        return 0;
}

int main()
{
    f1(2,4);
    f1();
    f1("wssb","wssb");
}
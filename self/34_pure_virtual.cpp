#include <iostream>
using namespace std;

class student
{
// student称为抽象类，即里面只有虚函数。这种函数连对象都不能创建。
private:
    /* data */
public:
    virtual void study() = 0;   //  纯虚函数，表示基类只提供一个函数名，具体功能由派生类改写。
};


class pupil : public student
{
private:

public:
    void study()
    {
        cout << "pupil" << endl;
    }

};


class daxueshen : public student
{
private:

public:
    void study()
    {
        cout << "pupil" << endl;
    }
};

int main(int argc, char const *argv[])
{
    // student s;   //创建对象就报错。
    pupil s1;
    pupil s2;
    s1.study();
    return 0;
}




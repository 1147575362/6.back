//虚函数的实现

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    /* data */
public:
    Student()
    {
        cout << "basis structor" << endl;
    }
    virtual ~Student()
    {
        cout << "basis Des" << endl;
    }
    virtual void study()
    {
        cout << "basis" << endl;
    }
};

class daxueshen : public Student
{
private:
    /* data */
public:
    daxueshen()
    {
        cout << "daxueshen structor" << endl;
    }
    ~daxueshen()
    {
        cout << "daxueshen Des" << endl;
    }
    void study() override
    {
        cout << "daxueshen" << endl;
    }
};

class xiaoxueshen : public Student
{
private:
    /* data */
public:
    xiaoxueshen()
    {
        cout << "xiaoxueshen structor" << endl;
    }
    ~xiaoxueshen()
    {
        cout << "xiaoxueshen Des" << endl;
    }
    void study() override
    {
        cout << "xiaoxueshen" << endl;
    }
};

void foo(Student *ps)
{
    ps->study();
};

int main(int argc, char const *argv[])
{
    //方式二：将派生类对象的地址传入函数
    // daxueshen d;
    // d.study();  //直接调用时，直接用大学生的函数
    // foo(&d); //用基类的指针指向派生类对象时，在基类加上虚函数，则调用派生类重写的那个函数


    //方式一：基类指针指向new出来的派生类
    //这种情况，编译器只会调用student的析构函数，而不会调用daxueshen的析构函数，造成资源泄露
    //解决方法是把student基类的析构函数设置为虚函数。
    Student *p = new daxueshen;
    // foo(p);
    delete p;
    return 0;
}

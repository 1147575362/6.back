//菱形继承

#include <iostream>
using namespace std;

class A
{
private:
    int _x;
    char _z;

public:
    A(int x) : _x(x)
    {
        cout << "A structor" << endl;
    }
    void print() const
    {
        cout << this->_x << endl;
    }
    // ~A();
};

class B : virtual public A
{
private:
    /* data */
public:
    B(int x) : A(x)
    {
        cout << "B structor" << endl;
    }

    // ~B();
};

class C : virtual public A
{
private:
    /* data */
public:
    C(int x) : A(x)
    {
        cout << "C structor" << endl;
    }

    // ~C();
};
class temp
{
public:
    temp()
    {
        cout << "temp structor" << endl;
    }
};

class D : public B, public C
{
private:
    // temp t;

public:
    D(int x) : B(x), C(x), A(x)
    {
        cout << "D structor" << endl;
    }
    // ~D();
};

int main(int argc, char const *argv[])
{
    D d(10);
    d.print();
    cout << sizeof(d) << endl;
    return 0;
}

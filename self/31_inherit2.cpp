//基类、派生类、派生类中类的构造函数、析构函数调用顺序

#include <iostream>
using namespace std;

class other
{
private:
    /* data */
public:
    other()
    {
        cout << "other structor" << endl;
    }
    ~other()
    {
        cout << "other Des" << endl;
    }
};

class Bases
{
private:
    int _age;

protected:
    int _score;

public:
    string _name;
    Bases() : _age(18), _name("leilei"), _score(90)
    {
        cout << "Bases stractor" << endl;
    }
    ~Bases()
    {
        cout << "Bases Des" << endl;
    }
};

class Derived : protected Bases
{
private:
    other o;

public:
    Derived()
    {
        cout << "Derived structor" << endl;
    }

    ~Derived()
    {
        cout << "Derived Des" << endl;
    }

    void print()
    {
        cout << this->_score << endl;
    }
};

int main(int argc, char const *argv[])
{
    Derived d;
    // d.print();
    return 0;
}

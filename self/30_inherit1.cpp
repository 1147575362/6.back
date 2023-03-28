//类继承的基本使用方法

#include <iostream>
#include <string>
using namespace std;

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
};

class Derived : protected Bases
{
private:
    /* data */
public:
    Derived()
    {
        cout << "Derived structor" << endl;
    }

    void print()
    {
        cout << this->_score << endl;
    }
};

int main(int argc, char const *argv[])
{
    Derived d;
    d.print();
    return 0;
}

//用设计模式的迭代器对象遍历输出A类中的成员变量

#include <iostream>
using namespace std;

class A
{
private:
    int a1;
    int a2;
    int a3;
    int a4;

public:
    A() : a1(10), a2(20), a3(30), a4(40){};

    void print()
    {
        cout << &a1 << endl;
        cout << &a2 << endl;
        cout << &a3 << endl;
    }

    class Iterator
    {
    private:
        int *p;

    public:
        Iterator(int *p) : p(p) {}
        int operator*() const
        {
            return *p;
        }
        Iterator &operator++()
        {
            p++;
            return *this;
        }
        bool operator!=(const Iterator &rhs) const
        {
            return p != rhs.p;
        }
    };
    Iterator begin()
    {
        return Iterator(&a1);
    }
    Iterator end()
    {
        return Iterator(&a1 + sizeof(A) / 4);
    }
};
int main(int argc, char const *argv[])
{

    A a;
    // for (auto it = a.begin(); it != a.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    for (const auto &m : a)
    {
        cout << m << "  ";
    }
    cout << endl;
    return 0;
}

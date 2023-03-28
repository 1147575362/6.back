#ifndef TEMPLETE5_HPP
#define TEMPLETE5_HPP
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray
{
private:
    T *Array;
    int len;
    T *p;
    int tag;

public:
    DynamicArray() : len(1), tag(0)
    {
        // 分配空间
        Array = new T[len];
        p = new T;
        p = Array;
    }
    ~DynamicArray()
    {
        p = nullptr;
        delete[] Array;
        Array = nullptr;
    }
    void push_back(T value) // auto expensive
    {
        *p = value;
        p++;
        tag++;
        if (tag == len) // start expensive
        {
            T *temp_array = new T[len];
            for (int i = 0; i < len; i++)
                temp_array[i] = Array[i]; // copy
            len *= 2;                     // expensive sizex2
            delete[] Array;
            Array = new T[len]; // new expensived address
            for (int i = 0; i < len / 2; i++)
                Array[i] = temp_array[i];
            delete[] temp_array;

            p = &Array[len / 2]; // p重新指向array新分配的地址的交界处
        }
    }
    void print()
    {
        for (int i = 0; i < len; i++)
            cout << Array[i] << " ";
        cout << endl;

        //-----test-----//
        // cout << *p << endl;
    }

    void pop_back()
    {
        p--;
        *p = (int)0;
    }

    int size() const
    {
        return this->len;
    }
    bool empty() const
    {
        return (p == Array) ? true : false;
    }

    // 迭代器
    class Iterator
    {
    private:
        T *Ip;

    public:
        Iterator(T *p) : Ip(p) {}
        T &operator*()
        {
            return *Ip;
        }
        bool operator!=(const Iterator &rhs) const
        {
            return this->Ip != rhs.Ip;
        }
        Iterator &operator++()
        {
            Ip++;
            return *this;
        }
    };

    Iterator begin()
    {
        return Iterator(this->Array);
    }

    Iterator end()
    {
        return Iterator(p);
    }
};

template <typename F>
int max_range(F f1, F f2)
{
    int MIN = -1024;
    for (auto it = f1; it != f2; ++it)
    {
        if (*it > MIN)
            MIN = *it;
    }
    return MIN;
}

template <typename F>
int min_range(F f1, F f2)
{
    int MAX = 1024;
    for (auto it = f1; it != f2; ++it)
    {
        if (*it < MAX)
            MAX = *it;
    }
    return MAX;
}

template <typename F, typename T>
auto find(F f1, F f2, T x)
{
    for (auto it = f1; it != f2; ++it)
    {
        if (*it == x)
            return it;
    }
    throw std::runtime_error("cant find!");
}

template <typename T>
inline void exchange(T &a, T &b)
{
    T t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}

template <typename T>
bool func_order(T a, T b)
{
    return a > b;
}
template <typename T>
bool func_reverse(T a, T b)
{
    return a < b;
}

template <typename F>
void sort(F f1, F f2, string tag)
{
    if (tag == "order")
    {
        for (auto i = f1; i != f2; ++i)
            for (auto j = i; j != f2; ++j)
                if (func_order(*i , *j))
                {
                    exchange(*i, *j);
                }
    }

    else if (tag == "reverse")
    {
        for (auto i = f1; i != f2; ++i)
            for (auto j = i; j != f2; ++j)
                if (func_reverse(*i , *j))
                {
                    exchange(*i, *j);
                }
    }
    else
        throw std::runtime_error("order argument input error!");
}

#endif

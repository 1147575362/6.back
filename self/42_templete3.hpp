#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
    int top;
    T *data;
    int max_size;

public:
    Stack(int n) : top(-1), max_size(n)
    {
        data = new T[n];
    }
    ~Stack()
    {
        delete[] data;
        data = nullptr;
    }

    void pop()
    {
        if (top <= -1)
            throw std::out_of_range("out of range in pop");
        --top;
    }
    void push(T x)
    {
        if (top >= max_size - 1)
            throw std::out_of_range("out of range in push");
        data[++top] = x;
    }
    bool empty()
    {
        return top <= -1 ? true : false;
    }
    T get_top()
    {
        return data[top];
    }
};


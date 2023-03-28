#include <iostream>
#include <deque>
using namespace std;

template <typename T>
class queue
{
private:
    std::deque<T> c;     //用容器适配器定义队列，就是用deque的一些功能来封装queue

public:
    void dequeue()
    {
        c.pop_front();
    }

    void inqueue(T x)
    {
        c.push_back(x);
    }

    int size()
    {
        return c.size();
    }

    bool empty()
    {
        return c.empty();
    }

    T get_front()
    {
        return c.front();
    }

    T get_back()
    {
        return c.back();
    }

    void print()
    {
        while (!empty())
        {
            cout << get_front() << " ";
            dequeue();
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.inqueue(1);
    q.inqueue(2);
    q.inqueue(3);
    q.print();
    cout << "size is:" << q.size() << endl
         << "is empty?" << q.empty() << endl;
    return 0;
}

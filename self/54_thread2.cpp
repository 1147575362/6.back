// 线程互斥锁

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

class Demo
{
private:
    long long num = 1;
    std::mutex m;

public:
    //    Demo(int x) : num(x){}
    void go(int x)
    {
        for (int i = 0; i < x; i++)
        {
            {
                lock_guard<mutex> lg(m);
                num = num* 2;
            }
        }
    }
    void print()
    {
        cout << num << endl;
    }
};

int main(int argc, char const *argv[])
{
    Demo d;
    std::thread t1(&Demo::go, &d, 4);
    std::thread t2(&Demo::go, &d, 4);

    t1.join();
    t2.join();

    d.print();
    return 0;
}

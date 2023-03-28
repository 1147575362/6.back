// 线程初体验

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void global_func1(int x, int y)
{
    cout << "global pthread created!" << endl;
    cout << "x = " << x << endl;
    cout << "&&y = " << y << endl;
}

class Demo
{
private:
    /* data */
public:
    // Demo(/* args */);
    void f1()
    {
        this_thread::sleep_for(1s);
        for (int i = 5; i >= 1; i--)
        {
            cout << i << "..." << endl;
            std::this_thread::sleep_for(1000ms);
        }
        cout << "lauch!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Demo d1;
    int &&a = 100 + 1;
    std::thread t1(global_func1, 100, std::ref(a));
    std::thread t2(&Demo::f1, &d1);
    t1.join();
    t2.join();
    return 0;
}

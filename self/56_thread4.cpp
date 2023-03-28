/*
实现一个能在多任务环境下工作的任务队列(用模板)：
若多个线程同时往一个队列中写数据，要能保证数据正确；
若多个线程同时出队，要能保证数据正确，若队列中没有数据，则等待。
*/
//没写出来
#include <iostream>
#include <string>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

// 用条件变量解决队列中没有数据则等待的问题。
template <typename T>
class queue

{
private:
    std::deque<T> c; // 用容器适配器定义队列，就是用deque的一些功能来封装queue

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

std::mutex m;
std::condition_variable cv;
// bool empty = false;

void f1_push(queue<int> *tq)
{
    cout << "f1写入5个数据\n";

    std::lock_guard<std::mutex> lq(m);
    tq->inqueue(1);
    tq->inqueue(2);
    tq->inqueue(3);
    tq->inqueue(4);
    tq->inqueue(5);
    cout << tq->empty() << endl;
    cv.notify_one();
}

void f2_push(queue<int> *tq)
{
    cout << "f2写入5个数据\n";

    std::lock_guard<std::mutex> lq(m);
    tq->inqueue(100);
    tq->inqueue(200);
    tq->inqueue(300);
    tq->inqueue(400);
    tq->inqueue(500);
    cout << tq->empty() << endl;
    cv.notify_one();
}

void f3_pop(queue<int> *tq)
{
    std::unique_lock<std::mutex> ul(m);
    // cv.wait(ul, [tq]
    //         {cout << "pop发现队列为空，正在等待填入中...\n"; return !(tq->empty()); }); // 如果tq为空，则返回1,not后为0，则ul会一直锁着

    while ((tq->empty()))
    {
        cout << tq->empty() << endl;
        cv.wait(ul);
    }

    // 解锁后
    {
        std::lock_guard<std::mutex> lq(m); // 对队列要一把独占锁
        tq->dequeue();
    }
    // ul.unlock();
    cout << "pop完毕\n";
}

int main(int argc, char const *argv[])
{
    queue<int> q;

    std::thread t1(f1_push, &q);
    std::thread t3(f3_pop, &q);
    std::thread t2(f2_push, &q);

    t1.join();
    t2.join();

    t3.join();
    q.print();

    return 0;
}

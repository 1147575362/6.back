//条件变量示例
//实际就是主线程和子线程交替写数据，主线程在写的时候子线程就得调用wait等，写完后给子线程发送notify_one激活子线程，并进入wait状态；
//子线程写完后同样发信号给主线程，主线程捕获后才继续执行。

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{   
    std::unique_lock<std::mutex> lk(m); 
    cv.wait(lk, []{return ready;}); //只要ready一直为false，lk就一直锁着，直到ready为true
    //上面这句可以换成：
    // while(!ready)
    // {
    //     cv.wait(lk);
    // }   //用while而不用if，是因为wait被唤醒后，可以再进一次while判断，防止虚假唤醒
    
    cout << "子线程的信号数据已准备好，正在写入中。。。\n";
    data += "after processing ";

    processed = true;
    cout << "子线程数据已经写入，可以返回主线程了\n";

    // lk.unlock(); //这句话有没有好像没关系
    cv.notify_one();
}
   


int main(int argc, char const *argv[])
{
    std::thread worker(worker_thread);

    data = "Example data ";
    
    {
        std::lock_guard<std::mutex> lk(m);  //用于保护ready原子性
        ready = true;
        cout << "主函数的数据已经写入，主线程进入等待状态，可以去子线程了\n";        
    }
    cv.notify_one();

    //开始等待子线程写入完成
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }

    cout << "欢迎再次回到主线程，数据为：" << data << endl;

    worker.join();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class f1
{
private:
    int x_;
    int *p_;
public:
    f1(const f1 &rhs):x_(rhs.x_)    //自定义拷贝构造函数，这里的rhs是p1对象 
    {
        cout << "kaobei" << endl;
        
        p_ = new int[5];            //为了防止p1和p2指向同一块地址，这里把p2的指针重新new出空间，在复制值进去
                                    //这样p1改变指针指向的地址的值，p2则不会随之变动。
        for(int i = 0; i<5;i++)
            p_[i] = rhs.p_[i];
    }
    f1(int x):x_(x)
    {
        cout << "gouzao" << endl;
        p_ = new int[3]{1,2,3};
    }
    ~f1()
    {
        cout << "xigou" << endl;
        delete [] p_;
        p_ = nullptr;
    }

    void print()
    {
        cout << x_ << endl;
        for(int i = 0; i < 3; i++)
            cout << p_[i] << ",";
        cout << endl;
    }

    void set_p()    //这里改变指针指向的地址的值
    {
        p_[0] = 100;
    }
};



int main(int argc, char const *argv[])
{
    f1 a(10);
    f1 b = a;
    a.set_p();
    a.print();
    b.print();
    
    return 0;
}

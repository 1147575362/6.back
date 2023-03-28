#include <iostream>
#include <thread>
using namespace std;

class SmallInt
{
private:
    int _data;

public:
    friend SmallInt operator+(SmallInt a, SmallInt b);
    friend bool operator==(SmallInt a, SmallInt b);
    friend std::ostream &operator<<(std::ostream &out, const SmallInt &x);
    

    SmallInt(int data) // 构造函数
    {
        if (data > 255 or data < 0)
            throw std::out_of_range("越界");
        _data = data;
    }

    SmallInt operator-(SmallInt b) // 成员运算符重载
    {
        SmallInt temp(0);
        temp._data = this->_data - b._data;
        return temp;
    }

    SmallInt &operator--() // 前--
    {
        this->_data--;
        return *this;
    }

    SmallInt &operator--(int) // 后-- 这个int不参与运算，只是为了区分前--和后--
    {
        --this->_data;
        return *this;
    }

    bool operator()(int a, int b) // 函数调用运算符
    {
        return a > b;
    }

    int get_data()
    {
        return this->_data;
    }
};

SmallInt operator+(SmallInt a, SmallInt b) // 非成员运算符重载
{
    return a._data + b._data;
}

bool operator==(SmallInt a, SmallInt b)
{
    return (a._data == b._data);
}  

std::ostream &operator<<(std::ostream &out, const SmallInt &x)  
//这里ostream的引用是因为不能返回ostream的值或者说复制ostream的值，因为规定标准库只能有一个。
{
    return out << x._data;
}



int main(int argc, char const *argv[])
{
    SmallInt a(80);
    SmallInt b(20);
    SmallInt c(0);
    SmallInt d(0);
    c = a + b;
    d = a - b;


    //以下为测试
    cout << --a << endl;       // 这个称为前--
    cout << a-- << endl;       // 这个成为后--；这两个在成员函数里的区分是有无哑元
    cout << a(30, 10) << endl; // 函数调用运算符
    // cout << d << endl;
    // cout << c.get_data() << endl;
    // cout << (a == b) << endl;
    // cout << a << endl;
    return 0;
}

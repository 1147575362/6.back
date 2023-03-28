/*定义一个类型，成员为一个char*, 在构造函数中申请资源
请实现该类的拷贝构造函数 和 拷贝赋值运算符函数 和 析构函数。*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String
{
private:
    char *_s;

public:
    String(const char *s = nullptr);
    String(const String &rhs);
    String &operator=(const String &other);
    friend std::ostream &operator<<(std::ostream &out, const String &s); // 非成员函数
    ~String();
    char at(int i) const;
    String set();
    int size() const;
};

int main(int argc, char const *argv[])
{
    String s1("hello,world");
    // String s2 = s1;
    String s2;
    s2 = s1;
    cout << s1 << "," << s1.size() << endl;
    cout << s2 << "," << s2.size() << endl;
    s1.set();
    cout << s1 << "," << s1.size() << endl;
    cout << s2 << "," << s2.size() << endl;
    cout << s2.at(3) << endl;
    return 0;
}

String::String(const char *s)
{
    if (s == nullptr)
    {
        this->_s = new char[1];
        _s[0] = '\0';
    }
    else
    {
        this->_s = new char[strlen(s)];
        strcpy(_s, s);
    }
}

String::String(const String &rhs)
{
    if (rhs._s == nullptr)
    {
        this->_s = new char[1];
        _s[0] = '\0';
    }
    else
    {
        this->_s = new char[strlen(rhs._s)];
        strcpy(_s, rhs._s);
    }
}

String::~String()
{
    delete[] _s;
    _s = nullptr;
}

String &String::operator=(const String &other)
{
    if (other._s == nullptr)
    {
        this->_s = new char[1];
        _s[0] = '\0';
    }
    else
    {
        this->_s = new char[strlen(other._s)];
        strcpy(_s, other._s);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    return out << s._s;
}

char String::at(int i) const
{
    if (i <= 0 or i > this->size())
        throw std::out_of_range("out of range in line 95");
    return this->_s[i - 1];
}

String String::set()
{
    int i;
    char c;
    cout << "Please enter the number of bytes you want to modify, and enter the bytes you want to modify" << endl;
    cin >> i >> c;
    if (i <= 0 or i > this->size())
        throw std::out_of_range("out of range in line 102");
    this->_s[i - 1] = c;
    return *this;
}

int String::size() const
{
    return strlen(this->_s);
}
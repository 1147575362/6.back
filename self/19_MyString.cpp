#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class String
{
private:
    char *data;

public:
    friend std::ostream &operator<<(std::ostream &out, const String &s);
    friend String operator+(String a, String b);

    explicit String(const char *s = nullptr)
    {
        cout << "构造函数" << endl;
        if (s == nullptr)
        {
            data = new char[1];
            data[0] = '\0';
        }
        else
        {
            data = new char[strlen(s) + 1];
            strcpy(data, s);
        }
    }

    String &operator=(const String &other)
    {
        if (this == &other)
            return *this;
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
        return *this;
    }

    String &operator=(const string s)
    {
        delete[] data;
        data = new char[s.size() + 1];
        strcpy(this->data, s.c_str());
        return *this;
    }

    int size() const
    {
        return strlen(this->data);
    }

    bool empty() const
    {
        if (size())
            return false;
        else
            return true;
    }

    char at(int x)
    {
        if (x < 0 or x > this->size())
            throw std::out_of_range("at越界");
        return this->data[x - 1];
    }

    char *get_data() const
    {
        return this->data;
    }

    ~String()
    {
        cout << "析构函数" << endl;
        // delete [] data;  //段错误
        data = nullptr;
    }
};

String operator+(String a, String b)
{
    a.data = strcat(a.data, b.data);
    return a;
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    return out << s.data;
}

int main(int argc, char const *argv[])
{
    String a("zc!");
    String b("I hate u!");
    cout << a << endl;
    cout << b << endl;

    a = "ll!";
    cout << a << " , " << &a << endl;
    cout << b << " , " << &b << endl;

    b = a;
    cout << a << " , " << &a << endl;
    cout << b << " , " << &b << endl;
    cout << "是否为空？" << a.empty() << endl;
    cout << "字符个数为" << a.size() << endl;
    cout << "第二个字符为" << a.at(1) << endl;
    cout << a + b << endl;

    return 0;
}

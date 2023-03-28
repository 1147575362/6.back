#ifndef TEMPLETE2_HPP
#define TEMPLETE2_HPP
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student // 定义一个学生类用来排序
{
private:
public:
    Student() = default;
    Student(string n, int s) : name(n), score(s) {}
    friend std::ostream &operator<<(std::ostream &out, const Student &x)
    {
        if (x.name == "")
            return out << "null";
        else
            return out << "Student(" << x.name << ", " << x.score << ")";
    }

    bool operator<(const Student &rhs)
    {
        return this->score < rhs.score;
    }

    std::string name;
    int score;
};

// template <typename T>
// void print(T a[], int len)
// {
//     for (int i = 0; i < len; i++)
//         cout << a[i] << ", ";
//     cout << endl;
// }

template <typename T>
inline void exchange(T &a, T &b)
{
    T t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}

template <typename T>
inline void sort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j + 1] < a[j])
            {
                exchange(a[j], a[j + 1]);
            }
}

#endif
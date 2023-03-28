//模板初体验
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T max_(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <typename T>
T min_(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T1, typename T2>
int find(T1 &a, T2 x)
{
    // cout << sizeof(a) << endl;
    // cout << sizeof(a[0]) << endl;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (a[i] == x)
            return i + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    // cout << max_(1, 2) << endl;
    // cout << min_(2.1, 1.4) << endl;
    int a[5] = {1, 2, 3, 4, 5};
    double b[3] = {1.4, 2.6, 3.14};
    // cout << find(a, 5) << endl;

    cout << find(b, 1.4) << endl;
    return 0;
}

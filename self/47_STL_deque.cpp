#include <iostream>
#include <deque>
using namespace std;
void print(int id, deque<int> &v)
{
    cout << "(" << id << ") ";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    deque<int> d = {8, 4, 7, 1, 9};
    print(1, d);

    // 元素覆盖
    //  d.assign(3, 666);   //以3份666副本覆盖原有的所有内容
    //  print(1, d);

    // 元素访问
    cout << d.at(1) << endl;
    cout << d.back() << endl;
    cout << d.front() << endl;
    cout << d[1] << endl;

    // 修改器
    //  d.clear();  //清除所有内容
    //  print(2,d);
    auto it = d.begin();
    d.insert(it, 666); // 迭代器指定位置，然后插入元素
    print(2, d);
    cout << *it << endl;

    d.emplace(it, 888);
    print(3, d);
    cout << *it << endl;
    // 两者区别：
    // insert是插入一个完全的对象，
    // 而emplace是先调用该对象的构造函数生成的对象，再把这个对象插入vector中。使用emplace时，该对象类必须有相应的构造函数。

    d.erase(it);
    print(4, d);
    cout << *it << endl;
    // 这里要注意it指针的位置，插入位置都是在指针前面插入，而删除则是在指针指向的位置删除，删除后it指向后面跟上来的元素。

    d.push_back(100); // 后插
    print(5, d);

    d.emplace_back(200); // 后插
    print(6, d);

    d.pop_back(); // 后删
    print(7, d);

    d.push_front(300); // 前插
    print(8, d);

    d.resize(5); // 重新设置大小，后面多的直接截断
    print(9, d);
    return 0;
}

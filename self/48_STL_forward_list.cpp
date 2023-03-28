#include <iostream>
#include <forward_list>
using namespace std;

void print(int id, const forward_list<int> &v)
{
    cout << "(" << id << ") ";
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    forward_list<int> f = {3, 4, 1, 7, 2};
    print(1, f);

    // f.assign(10, 6);    //以10份6副本覆盖f的所有内容
    // print(2,f);

    // 元素访问
    cout << f.front() << endl;

    // 修改器
    //  f.clear();  //清除内容
    auto it = f.begin();
    f.insert_after(it, 100);    //再某个元素之后插入新元素(deque是在某个元素之前插入)
    print(2, f);

    f.emplace_after(it,200);    //在元素后原位构造元素
    print(3,f);

    f.erase_after(it);  //删除元素后的元素
    print(4,f);

    f.push_front(300);  //头部插入
    print(5,f);

    f.pop_front();  //头部删除
    print(6,f);

    f.reverse();    //链表反转
    print(7,f);

    f.unique(); //删除连续的重复元素
    f.sort();   //排序
    print(8,f);
}

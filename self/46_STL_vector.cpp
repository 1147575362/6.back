#include <iostream>
#include <vector>
using namespace std;
void print(int id, vector<int> &v)
{
    cout << "(" << id << ") ";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "| capacity = " << v.capacity() << endl;
}

int main(int argc, char const *argv[])
{
    // 创建、查询
    vector<int> v1 = {8, 7, 2, 6, 4, 3};
    vector<int> v2(3, 200);    // 放入3个200
    cout << v1.at(1) << endl;  // at有越界检查,[]没有
    cout << v1.back() << endl; // 返回最后一个元素的值
    cout << v1.size() << endl; // 返回大小
    print(1, v1);

    // 分配空间
    v1.reserve(10);                // 预定10个空间
    cout << v1.capacity() << endl; // 打印所能容纳的元素数
    // v1.resize(10);                 // 分配10个空间，但这个空间里面已经被占用了
    v1.shrink_to_fit();            // 收缩(释放)空间以减少内存使用
    cout << v1.capacity() << endl; // 打印所能容纳的元素数

    // 插入元素
    auto it = v1.begin();
    v1.insert(++it, 100); // insert的第一个参数类型是迭代器类型,插入指定元素到指定位置后面，若空间不够则自动扩容(翻一倍)
    print(2, v1);
    // v1.emplace(++it, 200);         // emplace是放置一个元素到指定位置后面，如果空间不够则失效,这里搜索空间了所以导致double free
    print(3, v1);

    // 用erase移除所有偶数 不会缩减容量
    // erase会使删除指定位置元素，使指定移除位置的迭代器失效，然后返回一个后面上来的迭代器
    for (auto it = v1.begin(); it != v1.end();)
    {
        if (not(*it % 2))
            it = v1.erase(it);
        else
            it++;
    }
    print(4, v1);

    cout << v1.at(0) << endl;   //at访问碎片空间，会直接outof range报错
    cout << v1[2] << endl;      //[]访问碎片空间，会返回最后那个元素的值  

    v1.shrink_to_fit();
    print(5, v1);

    // 移除末尾元素  不会缩减容量
    v1.pop_back();
    print(6, v1);

    // 尾插  可以自动扩容
    v1.push_back(666);
    print(7, v1);

    // 尾部放置元素 可自动扩容
    v1.emplace_back(888);
    print(8, v1);

    // v1.reserve(20);  //reserve只是扩容
    v1.resize(20);  //resize不止扩容，还把空的地方自动补零
    print(9,v1);
    return 0;
}

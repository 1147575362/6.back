#include <iostream>
#include <set>
using namespace std;

void print(const set<int> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    std::set<int> a = {1,7,6,0,8,4,5,3,7,7,8};
    print(a); // 重复的不打印？？！还只按小→大的顺序打印！NB 可用于去重

    cout << "size is: " << a.size() << endl;
    a.insert(100);
    print(a);
    a.emplace(200);
    print(a);

    auto it = a.begin();
    it = a.erase(++it); //erase返回补上来的那个元素的迭代器
    print(a);
    cout << *it << endl;
    
    cout << "有这个数字吗？" << a.count(0) << endl; //只返回1 or 0
    it = a.find(5);         //找到则返回这个键的迭代器，找不到则返回end迭代器(我的end为什么在5？)
    cout << *it << endl;

}

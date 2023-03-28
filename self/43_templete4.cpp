// 类模板写一个链表
#include "43_templete4.hpp"

int main(int argc, char const *argv[])
{
    // LinkList<int> l;
    // l.rear_push(3);
    // l.rear_push(4);
    // l.rear_push(5);
    // l.print();
    // cout << "pop is :" <<  l.front_pop() << endl;
    // l.print();
    // cout << "list is Empty? " << l.empty() << endl;

    LinkList<string> l;
    l.rear_push(string("我"));
    l.rear_push(string("草"));
    l.rear_push(string("了"));
    l.print();
    cout << "pop is :" << l.front_pop() << endl;
    l.print();
    cout << "list is Empty? " << l.empty() << endl;
    return 0;
}

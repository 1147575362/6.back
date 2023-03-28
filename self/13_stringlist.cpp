/*这个是为照片路径链表作准备，制作电子相册的提前步骤*/
/*请给单链表类型 添加 拷贝构造函数、拷贝赋值函数、输出函数。*/
/*用设计模式的迭代器对象输出链表中的元素*/

#include "13_stringlist.hpp"
#include <iostream>
#include <string>

using namespace std;

ForwardList::Node::Node(ElemType value) : data(value), next(nullptr) {} // Node类构造函数

ForwardList::ForwardList() : _head(nullptr), _size(0) // 构造函数
{
    cout << "list created!" << endl;
}

ForwardList::ForwardList(const ForwardList &rhs) : _head(nullptr), _size(0) // 拷贝构造函数
{
    // 拷贝构造函数测试成功
    cout << "copy created!" << endl;
    Node *p1 = rhs._head;
    while (p1)
    {
        push_rear(p1->data);
        p1 = p1->next;
    }
}

ForwardList::~ForwardList()
{

    while (_size)
    {
        pop_front();
    }
    cout << "析构已完成" << endl;
}

ForwardList &ForwardList::operator=(const ForwardList &temp) // 拷贝赋值运算符函数
{
    cout << "= created!" << endl;
    this->_head = nullptr;
    Node *p1 = temp._head;
    while (p1)
    {
        push_rear(p1->data);
        p1 = p1->next;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ForwardList &x)
{
    for (int i = 1; i <= x.size(); i++)
        out << x.at(i);
    return out;
}

void ForwardList::push_front(ElemType value)
{
    Node *p = new Node(value); // 这里直接给p的data域赋值value了？是的 Node是一个类，
    // 这里用形参——>Node类的参数——>定义列表里的data，见这里第7行

    p->next = _head;
    _head = p;
    _size++;
}

void ForwardList::push_rear(ElemType value)
{
    Node *pnew = new Node(value); // 这里直接给p的data域赋值value了？是的 Node是一个类，
    // 这里用形参——>Node类的参数——>定义列表里的data，见这里第7行
    Node *p = this->_head;
    if (this->size() == 0)
    {
        _head = pnew;
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = pnew;
    }
    pnew->next = nullptr;
    this->_size++;
}

void ForwardList::pop_front()
{
    if (_head == nullptr)
        return;

    Node *p = _head;
    _head = _head->next;
    p->next = nullptr;
    delete p;

    _size--;
}

ElemType ForwardList::front() const
{
    if (_size == 0)
        throw std::runtime_error("链表已空！");
    return _head->data;
}

bool ForwardList::empty() const
{
    if (!_size)
        return true;
    else
        return false;
}

int ForwardList::size() const
{
    return _size;
}

ElemType ForwardList::at(int i) const
{
    if (i <= 0 or i > _size)
        throw std::out_of_range("at outrange");

    Node *p = _head;
    for (int n = 1; n < i; n++)
    {
        p = p->next;
    }
    return p->data;
}

void ForwardList::print() const
{
    Node *p = _head;
    for (int i = 0; i < _size; i++)
    {
        cout << p->data << ",";
        p = p->next;
    }
    cout << endl;
}

//迭代器对象



int main(int argc, char const *argv[])
{
    ForwardList l;
    l.push_front("a");
    l.push_front("b");
    l.push_front("c");
    l.push_front("d");
    // //重载<<运算符函数测试
    // cout << l << endl;
    // cout << "------" << endl;

    // // 拷贝构造测试
    // ForwardList t = l;
    // l.push_front("test");
    // l.print();
    // t.print();
    // cout << "------" << endl;

    // 重载=运算符函数测试
    ForwardList t;
    t = l;
    l.push_front("test");
    l.print();
    t.print();

    // cout << "链表是否为空？" <<l.empty() <<endl;
    // cout << "链表大小为" << l.size() << endl;
    // cout << "链表第一个元素的值为" << l.front() << endl;
    // cout << "链表第3个元素为" << l.at(3) << endl;
    // cout << "删除第一个元素后为" << endl;
    // l.pop_front();
    // l.print();
    return 0;
}

#ifndef STRINGLIST_HPP // 还不清楚这个到底什么意思
#define STRINGLIST_HPP
#include <iostream>
#include <string>
using namespace std;
using ElemType = std::string;

class ForwardList
{
private:
    struct Node // 内部类/嵌套类
    {
        Node() = default;
        Node(ElemType value); // 定义了Node类？
        ElemType data;        // 表示数据域
        struct Node *next;    // 表示指针域
    };
    Node *_head; // 头指针
    int _size;   // 表示元素个数

public:
    // typedef std::string ElemType;

    ForwardList();                                                            // 构造函数
    ForwardList(const ForwardList &rhs);                                      // 拷贝构造函数
    ~ForwardList();                                                           // 析构函数
    ForwardList &operator=(const ForwardList &temp);                          // 赋值运算符函数
    friend std::ostream &operator<<(std::ostream &out, const ForwardList &x); // 输出函数
    void push_front(ElemType value);                                          // 在头部插入数据
    void push_rear(ElemType value);                                           // 在尾部插入数据
    ElemType front() const;                                                   // 获取第一个元素的值
    void pop_front();                                                         // 删除第一个元素
    bool empty() const;                                                       // 判断链表是否为空
    int size() const;                                                         // 获取元素个数
    ElemType at(int i) const;                                                 // 获取链表的第i个元素
    void print() const;
    // 迭代器对象
    class iterator
    {
    private:
        Node *p;

    public:
        // iterator(Node *p) : p(p);
        ElemType operator*() const;
        iterator& operator++();
        bool operator!=(const iterator &rhs) const;
    };
    iterator begin();
    iterator end();
};
using StringList = ForwardList;

#endif
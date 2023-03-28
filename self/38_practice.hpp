#ifndef PRACTICE_HPP
#define PRACTICE_HPP
#include <iostream>
#include <string>
// using ElemType = Employee;
// using StringList = ForwardList;
using namespace std;

class Employee
{
private:
    string name;
    int cardnum;

public:
    virtual float calc_salary() = 0;
    virtual void print() = 0;
    void set_name(string n);
    string get_name() const;
    void set_cardnum(int num);
    int get_cardnum() const;
};

// 定薪员工
class fixedEmployee : public Employee
{
protected:
    float salary;

public:
    // fixedEmployee(float s); // 构造函数 ,用于设置固定工资

    float calc_salary() ;
    void print();
    void set_salary(float s);
    float get_salary() const;
};

// 纯提成员工
class ComEmployee : public Employee
{
protected:
    float sales_amount;
    float sales_percentage;

public:
    // ComEmployee(int x, float y); // 构造函数，用于设置属性
    float calc_salary() ;
    void print() override;
    void set_sales_amount(float x);
    void set_sales_percentage(float x);
    float get_sales_amount() const;
    float get_sales_percentage() const;
};

// 底薪加提成员工
class BasePlusComEmployee : public ComEmployee
{
protected:
    // ComEmployee com;
    float base_salary;

public:
    // BasePlusComEmployee(float a, int b, float c); // 构造函数，用于设置底薪
    float calc_salary() ;
    void print() override;
    void set_base_salary(int x);
    void set_sales_amount(int x);
    void set_sales_percentage(float x);
    int get_base_salary() const;
};


//链表
using ElemType = float;
// using StringList = ForwardList;

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
    // ForwardList(const ForwardList &rhs);                                      // 拷贝构造函数
    ~ForwardList();                                                           // 析构函数
    // ForwardList &operator=(const ForwardList &temp);                          // 赋值运算符函数
    friend std::ostream &operator<<(std::ostream &out, const ForwardList &x); // 输出函数
    void push_front(ElemType value);                                          // 在头部插入数据
    // void push_rear(ElemType value);                                           // 在尾部插入数据
    // ElemType front() const;                                                   // 获取第一个元素的值
    void pop_front();                                                         // 删除第一个元素
    bool empty() const;                                                       // 判断链表是否为空
    int size() const;                                                         // 获取元素个数
    ElemType at(int i) const;                                                 // 获取链表的第i个元素
    // void print() const;
    // 迭代器对象
//     class iterator
//     {
//     private:
//         Node *p;

//     public:
//         iterator(Node *p) : p(p);
//         ElemType operator*() const;
//         iterator& operator++();
//         bool operator!=(const iterator &rhs) const;
//     };
//     iterator begin();
//     iterator end();
};



#endif
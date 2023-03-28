#include "38_practice.hpp"
// 基类
void Employee::set_name(string n)
{
    this->name = n;
}

void Employee::set_cardnum(int num)
{
    this->cardnum = num;
}

string Employee::get_name() const
{
    return this->name;
}

int Employee::get_cardnum() const
{
    return this->cardnum;
}

// 定薪员工
// fixedEmployee::fixedEmployee(float s) : salary(s) {} // constructor

float fixedEmployee::calc_salary()
{
    return this->salary;
}

void fixedEmployee::print()
{
    cout << "name = " << this->get_name() << ", "
         << "cardnum = " << this->get_cardnum() << ", "
         << "salary = " << this->calc_salary() << endl;
}

void fixedEmployee::set_salary(float s)
{
    this->salary = s;
}

float fixedEmployee::get_salary() const
{
    return this->salary;
}

// 纯提成员工
// ComEmployee::ComEmployee(int x, float y) : sales_amount(x), sales_percentage(y) {} // constructor

float ComEmployee::calc_salary()
{
    return sales_amount * sales_percentage;
}

void ComEmployee::print()

{
    cout << "name = " << this->get_name() << ", "
         << "cardnum = " << this->get_cardnum() << ", "
         << "salary = " << this->calc_salary() << endl;
}

void ComEmployee::set_sales_amount(float x)
{
    this->sales_amount = x;
}

void ComEmployee::set_sales_percentage(float x)
{
    this->sales_percentage = x;
}

float ComEmployee::get_sales_amount() const
{
    return this->sales_amount;
}

float ComEmployee::get_sales_percentage() const
{
    return this->sales_percentage;
}

// 底薪加提成员工
// BasePlusComEmployee::BasePlusComEmployee(float a, int b, float c) // constructor
// {
//     base_salary = a;
//     this->sales_amount = b;
//     this->sales_percentage = c;
// }

float BasePlusComEmployee::calc_salary()
{
    return get_sales_amount() * get_sales_percentage() + this->base_salary;
}

void BasePlusComEmployee::print()
{
    cout << "name = " << this->get_name() << ", "
         << "cardnum = " << this->get_cardnum() << ", "
         << "salary = " << this->calc_salary() << endl;
}

void BasePlusComEmployee::set_base_salary(int x)
{
    this->base_salary = x;
}

void BasePlusComEmployee::set_sales_amount(int x)
{
    this->sales_amount = x;
}

void BasePlusComEmployee::set_sales_percentage(float x)
{
    this->sales_percentage = x;
}

int BasePlusComEmployee::get_base_salary() const
{
    return this->base_salary;
}

int main(int argc, char const *argv[])
{
    fixedEmployee e1;
    ComEmployee e2;
    BasePlusComEmployee e3;
    e1.set_name("张三");
    e1.set_cardnum(0001);
    e1.set_salary(3000);

    e2.set_name("赵四");
    e2.set_cardnum(0002);
    e2.set_sales_amount(10000);
    e2.set_sales_percentage(0.2);

    e3.set_name("王五");
    e3.set_cardnum(0003);
    e3.set_base_salary(2000);
    e3.set_sales_amount(10000);
    e3.set_sales_percentage(0.1);

    cout << e1.calc_salary() << endl;
    cout << e2.calc_salary() << endl;
    cout << e3.calc_salary() << endl;
    return 0;
}



ForwardList::Node::Node(Employee* value) : data(value->calc_salary()), next(nullptr) {} // Node类构造函数

ForwardList::ForwardList() : _head(nullptr), _size(0) // 构造函数
{
    cout << "list created!" << endl;
}


ForwardList::~ForwardList() // 析构函数
{

    while (_size)
    {
        pop_front();
    }
    cout << "析构已完成" << endl;
}

void ForwardList::push_front(ElemType value)
{
    Node *p = new Node(value); // 这里直接给p的data域赋值value了？是的 Node是一个类，
    // 这里用形参——>Node类的参数——>定义列表里的data，见这里第7行

    p->next = _head;
    _head = p;
    _size++;
}

std::ostream &operator<<(std::ostream &out, const ForwardList &x)
{
    for (int i = 1; i <= x.size(); i++)
        out << x.at(i);
    return out;
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

int ForwardList::size() const
{
    return _size;
}

bool ForwardList::empty() const
{
    if (!_size)
        return true;
    else
        return false;
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
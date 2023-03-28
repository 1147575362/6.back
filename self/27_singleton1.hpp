#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

class singleton
{
private:
    int x;
    static singleton s;

private:
    singleton(int value);
    singleton(const singleton &) = delete;            // 手动删除拷贝构造
    singleton &operator=(const singleton &) = delete; // 手动删出赋值运算符函数

public:
    int get_value() const;
    static singleton &get_s();
};

#endif
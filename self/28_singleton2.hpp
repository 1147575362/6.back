#ifndef SINGLETONG2_HPP
#define SINGLETONG2_HPP

class singleton2
{
private:
    int x;

private:
    singleton2(int value);
    singleton2(singleton2 const &) = delete;            // 删除拷贝构造函数
    singleton2 &operator=(singleton2 const &) = delete; // 删除赋值运算符函数

public:
    static singleton2& get_s();
    int get_value() const;
};

#endif
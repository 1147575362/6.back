////冒泡排序用函数模板实现
#include "40_templete2.hpp"

int main(int argc, char const *argv[])
{
    char a[5] = {'b', 'd', 'c', 'a', 'e'};
    sort(a, 5);
    print(a, 5);

    Student stus[3] = {Student(string("zhangfei"), 50), Student(string("guanyu"), 20), Student(string("liubei"), 100)};
    sort(stus, 3);
    print(stus, 3);
    return 0;
}

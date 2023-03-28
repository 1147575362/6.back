//类模板写一个栈

#include "42_templete3.hpp"
int main(int argc, char const *argv[])
{
    Stack<char> s(3);
    s.push('a');
    s.push('b');
    cout << s.get_top() << endl;
    s.pop();
    cout << s.get_top() << endl;
    cout << "is Empty? " << s.empty() << endl;
    return 0;
}

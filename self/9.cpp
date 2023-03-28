// class类

#include <iostream>
#include <string>
using namespace std;


// //第一种给属性赋值的方法：写行为函数传参赋值
// class Student
// {
// public:
//     void speak()
//     {
//         cout << age << "," << name << endl;
//     }
//     void set_age(int Age)
//     {
//         age = Age;
//     }
//     void set_name(string Name)
//     {
//         name = Name;
//     }

// private:
//     int age;
//     string name;
// };

// int main()
// {
//     Student a;
//     a.set_age(12);
//     a.set_name("leilei");
//     a.speak();

//     return 0;
// }


// //第二种给属性赋值的方法：在类里面直接赋值
// class Student
// {
// public:
//     void speak()
//     {
//         cout << age << "," << name << endl;
//     }

// private:
//     int age = 14;
//     string name = "sb";
// };

// int main()
// {
//     Student a;
//     a.speak();

//     return 0;
// }

//第三种给属性赋值的方法：函数形参调用赋值
class Student
{
public:
    void speak(int age, string name)
    {
        cout << age << "," << name << endl;
    }

private:
    int age;
    string name;
};

int main()
{
    Student a;
    a.speak(18,"leilei");

    return 0;
}
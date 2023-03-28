#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string s, int n) : name(s), score(n) {}
    int get_score()
    {
        return score;
    }

    string get_name()
    {
        return name;
    }

    void print()
    {
        cout << "name : " << name << ", score : " << score << endl;
    }
};

void print_vector(vector<Student> &v)
{
    for (auto x : v)
    {
        x.print();
    }
}

int main(int argc, char const *argv[])
{
    Student s[3] = {Student("leilei", 90), Student("huangcong", 50), Student("denglaoban", 80)};
    std::vector<Student> v = {s[0], s[1], s[2]};

    // at和[]返回的是对象的引用！
    v.at(1).print();
    v[0].print();

    // 插入对象
    Student s1("zc", 100);
    auto it = v.begin();
    (*it).print();
    v.insert(it, s1);
    print_vector(v);

    // 删除不及格的b
    for (auto x = v.begin(); x != v.end();)
    {
        if (x->get_score() < 60)
            x = v.erase(x);
        else
            x++;
    }
    cout << "及格的： " << endl;
    print_vector(v);
    cout << endl;

    // 尾插
    Student s2("lv", 59);
    v.push_back(s2);
    print_vector(v);
    cout << endl;

    // 用算法库的sort,按分数从小到大排序
    std::sort(v.begin(), v.end(), [](Student &x, Student &y)
              { return x.get_score() < y.get_score(); });
    print_vector(v);
}

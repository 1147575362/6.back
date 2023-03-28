#include <iostream>
#include <map>
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

void print_map(map<int, Student> &d)
{
    for (auto x = d.begin(); x != d.end(); ++x)
    {
        cout << x->first  << ": " << (x->second).get_name() << ", " << (x->second).get_score() << endl;
    }
}

int main(int argc, char const *argv[])
{
    Student s[3] = {Student("leilei", 90), Student("huangcong", 50), Student("denglaoban", 80)};
    map<int, Student> dict ;
    dict.insert(make_pair(3,s[0]));
    dict.insert(make_pair(1,s[1]));
    dict.insert(make_pair(2,s[2]));
    print_map(dict);    //默认按键排序
    cout << "size = "<< dict.size()<< endl;
    cout << endl;

    cout << (dict.at(1)).get_score() << endl;   //at传进去的是key
    // cout << dict[1].get_score() << endl;     //不会用
    // dict[0] = Student("sb", 0);  //  不会用

    //修改器
    auto it = dict.begin();
    Student t("naotan", 0);     
    it->second = t;     //可以修改second值，不能修改first键
    print_map(dict);  
    // dict.emplace(it, p1);

    return 0;
}

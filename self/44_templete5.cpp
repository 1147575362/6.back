// 写一个类模板，实现动态数组的功能
#include "44_templete5.hpp"
// #include "41_templete2.hpp"

int main(int argc, char const *argv[])
{
    /*----test 1----*/
    DynamicArray<int> da; // 空的数组
    cout << "is Empty? " << da.empty() << endl;
    da.push_back(2); // 添加
    da.print();

    da.push_back(1); // 添加
    da.push_back(3); // 添加
    da.push_back(2); // 添加
    da.push_back(4); // 添加
    da.push_back(9); // 添加
    da.push_back(7); // 添加
    da.print();
    da.push_back(8);  // 添加
    da.push_back(6);  // 添加
    da.push_back(10); // 添加
    da.push_back(11); // 添加
    da.pop_back();    // 删除
    da.print();

    da.push_back(11); // 添加
    da.print();

    da.pop_back(); // 删除
    da.pop_back(); // 删除
    da.pop_back(); // 删除
    da.print();

    cout << "is Empty? " << da.empty() << endl;
    cout << "size is : " << da.size() << endl;

    cout << "Iterator : ";
    for (auto it = da.begin(); it != da.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "max is :" << max_range(da.begin(), da.end()) << endl;
    cout << "min is :" << min_range(da.begin(), da.end()) << endl;
    cout << "find data is :" << *find(da.begin(), da.end(), 1) << endl;

    //string argument choose beteen：order\reverse  
    sort(da.begin(), da.end(), "reverse");
    cout << "sorted is : ";
    da.print();
    // cout << endl;

    // /*----test 2----*/
    // DynamicArray<string> db;
    // db.push_back("我"); // 添加
    // db.push_back("套");
    // db.push_back("你");
    // db.push_back("的");
    // db.push_back("猴");
    // db.push_back("子");
    // db.print();

    // db.pop_back();
    // cout << "Iterator : ";
    // for (auto it = db.begin(); it != db.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // /*----test 3----*/
    // Student stus[3] = {Student(string("zhangfei"), 50), Student(string("guanyu"), 20), Student(string("liubei"), 100)};
    // DynamicArray<Student> ds;
    // cout << "is Empty? " << ds.empty() << endl;
    // cout << "size is : " << ds.size() << endl;
    // ds.push_back(stus[0]);
    // ds.push_back(stus[1]);
    // ds.push_back(stus[2]);
    // ds.print();
    // cout << "is Empty? " << ds.empty() << endl;
    // cout << "size is : " << ds.size() << endl;
    // ds.pop_back();
    // ds.print();
    // cout << "is Empty? " << ds.empty() << endl;
    // cout << "size is : " << ds.size() << endl;
}
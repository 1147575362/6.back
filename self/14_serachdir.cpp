/*搜寻出当前目录下 所有文件的相对路径，并存到链表里面*/
#include "13_stringlist.hpp"
#include "14_serachdir.hpp"

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <fstream>
using namespace std;

Dir::Dir(std::string name) : _path_name(name), _dirp(nullptr)
{
    cout << "dir构造完成" << endl;
}

Dir::~Dir()
{
}

StringList Dir::getFileNames()  //不会写
{
    _dirp = open(_path_name);
}

int main(int argc, char const *argv[])
{
    Dir dir("./");
    StringList filenames = dir.getFileNames();
    // 创建了一个filenames的链表，而这个getfilenames函数得把目录里的文件名全部写到filenames里面
    for (int i = 0; i < filenames.size(); i++)
    {
        cout << filenames.at(i) << endl;
    }
    return 0;
}

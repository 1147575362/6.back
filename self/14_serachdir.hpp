#ifndef SERACHDIR_HPP
#define SERACHDIR_HPP


using StringList = ForwardList;
class Dir
{
public:
    Dir(std::string path_name);
    ~Dir();
    StringList getFileNames();

private:
    std::string _path_name;
    Dir* _dirp; //目录指针 这个到底什么意思？
};



#endif
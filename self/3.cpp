/* 
指针：

在计算机科学中，指针（英语：Pointer），
是编程语言中的一类数据类型及其对象或变量，用来表示或存储一个存储器地址，这个地址的值直接指向（points to）存在该地址的对象的值。

引用：

引用是一个对象的别名，主要用于函数参数和返回值类型，符号&X表示X类型的引用。
在C++编程语言中，引用是一种简单的引用数据类型，其功能不如从C继承的指针类型，但更安全。
C++引用的称可能会引起混淆，因为在计算机科学中，引用是一种通用的概念数据类型，指针和C++引用是特定的引用数据类型实现。

引用的的大小是其指向的对象的大小，因为引用仅仅是一个别名；
指针的大小与平台有关，在32位平台下指针大小为4个字节；
*/
#include <iostream>
using namespace std;

int main()
{
    //指针
	// int i = 1;
	// int* p = &i; // 这里&代表取地址 ；&i做右值是取地址，做左值是引用
	// cout << "i = " << i << endl;
	// cout << "&i = " << &i << endl;
    // cout << "p = " << p << endl;
	// cout << "*p = " << *p << endl;	//p是地址，*p是值
	

    // 引用
    // int i = 1;
    // int &j = i;
	// int t = i;
	// cout << "i = " << i <<endl;
	// cout << "&i = " << &i <<endl;
    // cout << "j = " << j << endl; 
	// cout << "&j = " << &j << endl; 	//这里j是值，&j是地址,这个地址与i的地址完全相同,所以叫做“别名”
	// cout << "t = " << t << endl;
	// cout << "&t = " << &t << endl;	//这个地址与j的地址不同
    

    // 可以看到对r执行++操作是直接反应到所指向的对象身上，对引用r的改变并不会是引用r的指向改变，它仍然指向i，并且会改变i的值；
    // 而如果是指针，则改变的是指针的值而非指向的对象。也就是说在引用初始化后对其的赋值等操作，都不会影响其指向，而是影响其指向的对象的内容。
    // int i = 10;
	// int* p = &i;
	// int& r = i;
	// cout << "i = " << i << endl;
	// cout << "p = " << p << endl;
	// cout << "r = " << r << endl;
	// r++;
	// cout << "r++ operation：" << endl;
	// cout << "i = " << i << endl;
	// cout << "p = " << p << endl;
	// cout << "r = " << r << endl;
	// p++;
	// cout << "p++ operation：" << endl;
	// cout << "i = " << i << endl;
	// cout << "p = " << p << endl;
	// cout << "r = " << r << endl;
	return 0;

// 总而言之，言而总之——它们的这些差别都可以归结为:
// "指针指向一块内存，它的内容是所指内存的地址；而引用则是某块内存的别名，引用不改变指向。"

}
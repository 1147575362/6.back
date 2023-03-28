#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/mman.h>
#include "lcd.hpp"
#include <unistd.h>
#include "color.hpp"
using namespace std;
Lcd::Lcd(std::string name) : _width(800), _height(480), _bpp(32)
{
    _fd = open(name.c_str(), O_RDWR);
    if (_fd == -1)
        throw std::runtime_error("open lcd error");

    _addr = static_cast<int *>(mmap(NULL, _width * _height * _bpp / 8, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0));
    if (_addr == MAP_FAILED)
    {
        throw std::runtime_error("mmap failed!");
    }

    cout << "lcd init success!" << endl;
}

Lcd::~Lcd()
{
    munmap(_addr, _width * _height * _bpp * 8);
    close(_fd);
}

void Lcd::drawPoint(int x, int y, Color color)
{
    if (x >= 0 and x < 800 and y >= 0 and y < 480)
        *(_addr + _width * y + x) = color.value();
}
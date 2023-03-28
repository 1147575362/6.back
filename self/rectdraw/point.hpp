#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    Point();
    Point(int x, int y);
    void move(int x, int y);
    int x() const;
    int y() const;
private:
    int _x;
    int _y;
};

#endif
#include <iostream>
using namespace std;

class Complex
{
private:
  double _x;
  double _y;

public:
  Complex(double x, double y) : _x(x), _y(y)
  {
  }

  friend Complex operator+(Complex a, Complex b);
  friend bool operator==(Complex a, Complex b);
  friend std::ostream &operator<<(std::ostream &out, const Complex &x);
  friend std::istream &operator>>(std::istream &input, Complex &x);
  friend bool operator<(Complex a, Complex b);
  friend bool operator>(Complex a, Complex b);
  friend Complex &operator--(Complex &t, int); // 后--
  friend Complex operator++(Complex &c1, int); // 后++
  Complex &operator--() // 前--
  {
    this->_x--;
    this->_y--;
    return *this;
  }

  Complex &operator++() // 前++
  {
    this->_x++;
    this->_y++;
    return *this;
  }


  void print()
  {
    cout << _x << "," << _y << "i" << endl;
  }
};

Complex operator+(Complex a, Complex b)
{
  Complex temp(0, 0);
  temp._x = a._x + b._x;
  temp._y = a._y + b._y;
  return temp;
}

bool operator==(Complex a, Complex b)
{
  if (a._x == b._x and a._y == b._y)
    return true;
  else
    return false;
}

bool operator<(Complex a, Complex b)
{
  if (a._x > b._x)
    return false;
  if (a._x < b._x)
    return true;
  if (a._x == b._x and a._y < b._y)
    return true;
  else
    return false;
}
bool operator>(Complex a, Complex b)
{
  return not(a < b or a == b);
}

std::ostream &operator<<(std::ostream &out, const Complex &x)
{
  return out << x._x << "," << x._y << "i" << endl;
}

std::istream &operator>>(std::istream &input, Complex &x)
{
  cout << "please input two float num" << endl;
  return input >> x._x >> x._y;
}

Complex &operator--(Complex &t, int) // 后--
{
  t._x--;
  t._y--;
  return t;
}

Complex operator++(Complex &c1, int) // 后++
{
  Complex t = c1;
  t._x++;
  t._y++;
  return t;
}

int fun()
{
  int x = 2;
  return (x++)+(x++); // (x = x + 1) + (x = x + 1)
                      //  x = x + 1  +  2 = 5;
}

int main(int argc, char const *argv[])
{
  Complex a(10, 20);
  Complex b(20, 30);
  cout << "a = " << a;
  cout << "b = " << b;
  (a + b).print();
  cout << "a == b? " << (a == b) << endl;
  cout << "a < b? " << (a < b) << endl;
  cout << "a > b? " << (a > b) << endl;
  a-- = --b;
  cout << a << endl;
  cout << fun() << endl;
  // cin >> a;
  // cout << a;
  return 0;
}

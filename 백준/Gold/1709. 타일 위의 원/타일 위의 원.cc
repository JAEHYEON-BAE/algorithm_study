// 1709

#include <iostream>
#include <cmath>

struct Point
{
  long long x, y;

  Point() {this->x=0;this->y=0;}
  Point(long long _x, long long _y) {
    this->x = _x;  this->y = _y;
  }
  long long d2() const {
    return x*x+y*y;
  }
  Point operator+(const Point& other) const {
    return {x+other.x, y+other.y};
  }
  void operator+=(const Point& other) {
    x += other.x;
    y += other.y;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;  std::cin >> n;
  long long r2 = n*n/4;

  Point p = {-n/2, -1};
  
  long long cnt = 0LL;
  
  while (p.x<=-1 && p.y>=-n/2) {
    ++cnt;
    if ((p+Point(1, 0)).d2()>r2) p += Point(1, 0);
    else if ((p+Point(1, 0)).d2()==r2) p += Point(1, -1);
    else p += Point(0, -1);
  }
  std::cout << cnt*4LL;
}

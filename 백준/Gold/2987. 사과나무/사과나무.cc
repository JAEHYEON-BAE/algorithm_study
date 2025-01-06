// 2987

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

struct Point
{
  long long x=0, y=0;

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
  Point operator-(const Point& other) const {
    return {x-other.x, y-other.y};
  }
  void operator-=(const Point& other) {
    x -= other.x;
    y -= other.y;
  }
  bool operator==(const Point& other) const {
    return (x==other.x && y==other.y);
  }

  int operator*(const Point& other) {
    return this->x * other.y - this->y * other.x;
  }
};

int ccw(const Point& p1, const Point& p2, const Point& p3)
{
  int cross = (p2-p1) * (p3-p1);
  if (cross==0) return 0;
  else return (cross>0)? 1: -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Point p1, p2, p3;
  std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  int area = std::fabs(p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y));
  std::cout << std::fixed << std::setprecision(1) << static_cast<long double>(area)/2.0L;
  
  int n;  std::cin >> n;
  
  int cnt=0;
  for (int i=0;i<n;++i) {
    Point apple;
    std::cin >> apple.x >> apple.y;

    if (apple==p1 || apple==p2 || apple==p3) {++cnt;continue;}
    
    int c1=ccw(p1, p2, apple), c2=ccw(p2, p3, apple), c3=ccw(p3, p1, apple);
    
    if (c1==0 && (apple.x-p1.x)*(apple.x-p2.x)<0) {++cnt;continue;}
    if (c2==0 && (apple.x-p2.x)*(apple.x-p3.x)<0) {++cnt;continue;}
    if (c3==0 && (apple.x-p3.x)*(apple.x-p1.x)<0) {++cnt;continue;}
    if (c1==c2 && c2==c3) {++cnt;continue;}
  }

  std::cout << '\n' << cnt;

    
 }

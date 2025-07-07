// 20149

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Point
{
  long long int x, y;
  Point(){}

  bool operator<(const Point &o) const {
    if (y==o.y) return x<o.x;
    return y<o.y;
  }
  bool operator==(const Point &o) const {
    return (x==o.x && y==o.y);
  }
};

struct Line
{
  // ax+by+c=0
  long long int a, b, c;
  long long int xs, xe;
  long long int ys, ye;
  Line(const Point &p1, const Point &p2) {
    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=p2.x*p1.y-p1.x*p2.y;

    xs=std::min(p1.x, p2.x);
    xe=std::max(p1.x, p2.x);

    ys=std::min(p1.y, p2.y);
    ye=std::max(p1.y, p2.y);
  }

  std::pair<bool, std::pair<long double, long double>> operator *(const Line &o) {
    if (a*o.b==o.a*b) {
      return {0, {0, 0}};
    }
    long double x=static_cast<long double>(b*o.c-o.b*c)/static_cast<long double>(a*o.b-o.a*b);
    long double y=static_cast<long double>(o.a*c-a*o.c)/static_cast<long double>(a*o.b-o.a*b);

    return {(x>=static_cast<long double>(xs) && x<=static_cast<long double>(xe) && y>=static_cast<long double>(ys) && y<=static_cast<long double>(ye) && x>=static_cast<long double>(o.xs) && x<=static_cast<long double>(o.xe) && y>=static_cast<long double>(o.ys) && y<=static_cast<long double>(o.ye)), {x, y}};
  }

  bool in(const Point &p) const {
    if (a*p.x+b*p.y+c!=0LL) return 0;

    return (a*p.x+b*p.y+c==0LL && p.x>=xs && p.x<=xe && p.y>=ys && p.y<=ye);
  }
};

int CCW(const Point &a, const Point &b, const Point &c)
{
  long long int t=(b.x-a.x)*(c.y-b.y) - (c.x-b.x)*(b.y-a.y);
  return t?t>0?1:-1:0;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  Point a, b, c, d;
  std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
  if (b<a) std::swap(a, b);
  if (d<c) std::swap(c, d);

  // 1. exactly same line
  if ((a==c && b==d) || (a==d && b==c)) {std::cout << '1'; return 0;}
  
  Line ab=Line(a, b);
  Line cd=Line(c, d);
  
  // 2. partially overlap
  //   2.1. a--c--d--b
  if (ab.in(c) && ab.in(d)) {std::cout << '1'; return 0;}
  //   2.2. c--a--b--d
  if (cd.in(a) && cd.in(b)) {std::cout << '1'; return 0;}
  //   2.3. a--c--b--d
  if (ab.in(c) && cd.in(b)) {
    std::cout << '1';
    if (b==c) std::cout << '\n' << b.x << ' ' << b.y;
    return 0;
  }
  //   2.4. c--a--d--b
  if (cd.in(a) && ab.in(d)) {
    std::cout << '1';
    if (a==d) std::cout << '\n' << a.x << ' ' << a.y;
    return 0;
  }

  // 3. meet at endpoint
  if (a==c || a==d) {
    std::cout << "1\n" << a.x << ' ' << a.y;
    return 0;
  }
  if (b==c || b==d) {
    std::cout << "1\n" << b.x << ' ' << b.y;
    return 0;
  }

  // 4. general case
  auto result=ab*cd;
  if (result.first) {
    std::cout << "1\n" << std::fixed << std::setprecision(10) << result.second.first << ' ' << result.second.second;
    return 0;
  }
  else std::cout << '0';
  return 0;
}
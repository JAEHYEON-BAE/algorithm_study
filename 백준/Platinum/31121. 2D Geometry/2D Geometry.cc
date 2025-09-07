// 31121

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
};

int GCD(int a, int b)
{
  a=std::abs(a);
  b=std::abs(b);
  if (a<b) std::swap(a, b);
  while (b) {
    int tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

struct Slope
{
  int dx, dy;

  Slope() {}
  Slope(int x, int y) {
    int g=GCD(x, y);
    x/=g, y/=g;
    
    if (x<0 || (x==0 && y<0)) x*=-1, y*=-1;
    dx=x, dy=y;
  }
  Slope(Point a, Point b): Slope(b.x-a.x, b.y-a.y) {}
  bool operator==(const Slope &o) const {
    return dx==o.dx && dy==o.dy;
  }
};

namespace std
{
  ostream &operator<<(std::ostream &os, const Point &p)
  {
    os << '(' << p.x << ", " << p.y << ')';
    return os;
  }
  ostream &operator<<(std::ostream &os, const Slope &s)
  {
    os << s.dx << " | " << s.dy;
    return os;
  }
  template<>
  struct hash<Slope> 
  {
    size_t operator()(const Slope &s) const {
      // cout << "For Slope " << s << ' ' << '\t';
      size_t x=static_cast<size_t>(s.dx+1'000'000'000)<<32 | static_cast<size_t>(s.dy+1'000'000'000);
      // cout << "HASH: " << x << endl;
      return x;
    }
  };
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;
  while (std::cin >> n) {
    std::vector<Point> points(n);
    for (Point &p:points) std::cin >> p.x >> p.y;

    int TRIALS=std::min(60, n);
    bool FLAG=TRIALS==n;

    int res=n;
    int heavy=0;

    bool EARLY_STOP=0;
    while (TRIALS--) {
      int idx=FLAG?TRIALS:rand()%n;
      Point std=points[idx];

      std::unordered_map<Slope, int> map;
      int max=0;
      for (int i=0;i<n;++i) if (i!=idx) {
        max=std::max(max, ++map[Slope(std, points[i])]);
      }
      ++max;
      // DEBUG(max);
      heavy=std::max(heavy, max);
      if (heavy>=(n>>1)) {EARLY_STOP=1;break;}
    }
    std::cout << std::max(n%3, std::max(0, 3*heavy-2*n)) << '\n';
  }
  
  return 0;
}
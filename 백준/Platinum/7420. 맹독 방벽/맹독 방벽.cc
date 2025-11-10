// 7420

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ld=long double;

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  bool operator<(const Point &o) const {
    return x<o.x || (x==o.x && y<o.y);
  }
};

ld dist(const Point &a, const Point &b)
{
  return std::sqrt(static_cast<ld>((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int CCW(const Point &a, const Point &b, const Point &c)
{
  int t=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
  return t?t>0?1:-1:0;
}

ld convexHull(const std::vector<Point> &p)
{
  std::vector<Point> upper, lower;
  int n=p.size();
  for (int i=0;i<n;++i) {
    while (upper.size()>1 && CCW(upper[upper.size()-2], upper.back(), p[i])>=0)
      upper.pop_back();
    upper.push_back(p[i]);
  }
  for (int i=n-1;i>=0;--i) {
    while (lower.size()>1 && CCW(lower[lower.size()-2], lower.back(), p[i])>=0)
      lower.pop_back();
    lower.push_back(p[i]);
  }

  ld res=0.0L;
  for (int i=1;i<upper.size();++i) res+=dist(upper[i-1], upper[i]);
  for (int i=1;i<lower.size();++i) res+=dist(lower[i-1], lower[i]);

  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, l;  std::cin >> n >> l;
  std::vector<Point> points(n);
  for (Point &p:points) std::cin >> p.x >> p.y;
  std::sort(points.begin(), points.end());
  ld ans=convexHull(points)+M_PI*2.0L*static_cast<ld>(l);

  std::cout << static_cast<int>(std::round(ans));
  
  return 0;
}
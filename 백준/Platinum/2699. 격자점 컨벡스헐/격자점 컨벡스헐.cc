// 2699

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}

  bool operator<(const Point &o) const {
    return x<o.x || (x==o.x && y<o.y);
  }
};

inline int CCW(const Point &a, const Point &b, const Point &c) 
{
  int t=(b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
  return t?t>0?1:-1:0;
}

std::vector<Point> convexHull(const std::vector<Point> &points)
{
  int n=points.size();

  std::vector<Point> lower, upper;
  for (const Point &p:points) {
    while (lower.size()>=2 && CCW(lower[lower.size()-2], lower.back(), p)<=0) lower.pop_back();
    lower.push_back(p);
  }
  for (int i=points.size()-1;i>=0;--i) {
    const Point &p=points[i];
    while (upper.size()>=2 && CCW(upper[upper.size()-2], upper.back(), p)<=0) upper.pop_back();
    upper.push_back(p);
  }

  lower.pop_back();
  upper.pop_back();

  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int p;  std::cin >> p;
  while (p--) {
    int n;  std::cin >> n;
    std::vector<Point> points(n);
    for (Point &p:points) std::cin >> p.x >> p.y;

    std::sort(points.begin(), points.end());
    
    std::vector<Point> hull=convexHull(points);
    std::reverse(hull.begin(), hull.end());

    int h=hull.size();

    int idx=0;
    Point max=hull[0];
    for (int i=1;i<h;++i) {
      if (hull[i].y>max.y || (hull[i].y==max.y && hull[i].x<max.x)) {
        max=hull[i];
        idx=i;
      } 
    }

    std::cout << h << '\n';
    for (int i=0;i<h;++i) {
      std::cout << hull[(idx+i)%h].x << ' ' << hull[(idx+i)%h].y << '\n';
    }
  }
  
  return 0;
}
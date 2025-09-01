// 2254

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}

  bool operator<(const Point &o) const {
    return x<o.x || (x==o.x && y<o.y);
  }
  bool operator==(const Point &o) const {
    return x==o.x && y==o.y;
  }
};

namespace std
{
  template <>
  struct hash<Point> 
  {
    std::size_t operator()(const Point &p) const noexcept {
      long long int x=1LL*p.x+100'000LL;
      long long int y=1LL*p.y+100'000LL;
      return x*200'001LL+y;
    }  
  };
}

inline int CCW(const Point &a, const Point &b, const Point &c)
{
  long long int t=1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
  return t?t>0?1:-1:0;
}

std::vector<Point> convexHull(std::vector<Point> &points)
{
  if (points.size()<3) return points;
  
  std::sort(points.begin(), points.end());
  std::vector<Point> lower, upper;

  for (Point &p:points) {
    while (lower.size()>=2 && CCW(lower[lower.size()-2], lower.back(), p)<=0) lower.pop_back();
    lower.push_back(p);
  }
  for (int i=points.size()-1;i>=0;--i) {
    Point &p=points[i];
    while (upper.size()>=2 && CCW(upper[upper.size()-2], upper.back(), p)<=0) upper.pop_back();
    upper.push_back(p);
  }

  lower.pop_back();
  upper.pop_back();

  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

bool insideHull(const Point &p, const std::vector<Point> &hull)
{
  int n=hull.size();
  if (n<3) return 0;

  if (CCW(hull[0], hull[1], p)<0 || CCW(hull[0], hull[n-1], p)>0) 
    return 0;

  int l=1, r=n-1;
  while (r-l>1) {
    int mid=(l+r)>>1;
    if (CCW(hull[0], hull[mid], p)>=0) l=mid;
    else r=mid;
  }
  return CCW(hull[l], hull[l+1], p)>=0;
}

void printHull(const std::vector<Point> &hull)
{
  for (const auto &p:hull) {
    std::cout << '(' << p.x << ", " << p.y << ") ";
  }
  std::cout << std::endl;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;
  Point prison;
  std::cin >> n >> prison.x >> prison.y;
  std::vector<Point> points(n);
  for (Point &p:points) std::cin >> p.x >> p.y;
  
  // 볼록껍질 생성 -> 이 볼록껍질 내부의 점들로 다시 볼록껍질 생성 -> 반복

  int cnt=0;
  while (1) {
    auto hull=convexHull(points);
    // printHull(hull);
    
    if (insideHull(prison, hull)) ++cnt;
    else break;

    std::unordered_set<Point> h;
    for (const Point &p:hull) h.insert(p);

    std::vector<Point> tmp;
    for (Point p:points) if (h.count(p)==0) {
      tmp.push_back(p);
    }
    points.swap(tmp);
  }
  std::cout << cnt;
  return 0;
}
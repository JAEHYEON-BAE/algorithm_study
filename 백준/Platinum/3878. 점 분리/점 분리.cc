// 3878

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
    return x<o.x||(x==o.x&&y<o.y);
  }
};

inline int CCW(const Point &a, const Point &b, const Point &c)
{
  int t=(b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
  return t?t>0?1:-1:0;
}

std::vector<Point> convexHull(std::vector<Point> &points)
{
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

bool intersect(Point a, Point b, Point c, Point d)
{
  int ab=CCW(a, b, c)*CCW(a, b, d);
  int cd=CCW(c, d, a)*CCW(c, d, b);

  if (ab==0 && cd==0) {
    if (b<a) std::swap(a, b);
    if (d<c) std::swap(c, d);
    
    return !(b<c || d<a);
  }
  return ab<=0 && cd<=0;
}

bool hullIntersect(const std::vector<Point> &a, const std::vector<Point> &b)
{
  int n=a.size(), m=b.size();
  if (n==1 || m==1) return 0;
  
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    if (intersect(a[i], a[(i+1)%n], b[j], b[(j+1)%m])) return 1;
  }
  return 0;
}

bool insideHull(const std::vector<Point> &hull, const Point &p)
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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, m;  std::cin >> n >> m;

    std::vector<Point> blacks(n), whites(m);
    for (Point &p:blacks) std::cin >> p.x >> p.y;
    for (Point &p:whites) std::cin >> p.x >> p.y;
    
    // blacks의 볼록껍질과 whites의 볼록껍질이 교차하는지 판단
    // 교차하지 않으면 Yes, 교차하면 No

    // 단순히 점 포함관계로는 예외 있음 (다윗의 별 같은 모양)
    // 모든 선분 쌍 사이의 교차 여부 확인 !

    if (n==1 && m==1) {
      std::cout << "YES\n";
      
      continue;
    }
    if (n==1 && m==2) {
      if (CCW(blacks[0], whites[0], whites[1])==0 && whites[0]<blacks[0] && blacks[0]<whites[1]) std::cout << "NO\n";
      else std::cout << "YES\n";
      
      continue;
    }
    if (n==2 && m==1) {
      if (CCW(blacks[0], blacks[1], whites[0])==0 && blacks[0]<whites[0] && whites[0]<blacks[1]) std::cout << "NO\n";
      else std::cout << "YES\n";

      continue;
    }
    if (n==2 && m==2) {
      if (intersect(blacks[0], blacks[1], whites[0], whites[1])) std::cout << "NO\n";
      else std::cout << "YES\n";

      continue;
    }

    std::vector<Point> black_hull=convexHull(blacks);
    std::vector<Point> white_hull=convexHull(whites);

    if (hullIntersect(black_hull, white_hull) || insideHull(black_hull, white_hull[0]) || insideHull(white_hull, black_hull[0])) {
      std::cout << "NO\n";
    }
    else std::cout << "YES\n";
  }

  return 0;
}
// 2987

#include <iostream>
#include <algorithm>
#include <vector>

struct Point
{
  long long x=0, y=0;
  long long operator-(const Point& other) const {
    return (x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
  }
};

bool is_righttri(const Point& p1, const Point& p2, const Point& p3)
{
  long long a2 = p1 - p2; 
  long long b2 = p2 - p3;
  long long c2 = p1 - p3;
  
  if (a2 + b2 == c2) return true;
  if (a2 + c2 == b2) return true;
  if (b2 + c2 == a2) return true;
  
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<Point> points(n);
  for (int i=0;i<n;++i) std::cin >> points[i].x >> points[i].y;

  int cnt=0;
  for (int i=0;i<n;++i) for (int j=i+1;j<n;++j) for (int k=j+1;k<n;++k) {
    if (is_righttri(points[i], points[j], points[k])) ++cnt;
  }

  std::cout << cnt;
}

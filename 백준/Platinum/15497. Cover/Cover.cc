// 15497

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

static constexpr long long int INF=(~0uLL)>>2;

struct Point
{
  long long int x, y;
  long long int area;
  Point() {}
  Point(long long int x, long long int y): x(x), y(y) {
    area=(x*y)<<2;
  }
  bool operator<(const Point &o) const {
    return x==o.x?y<o.y:x<o.x;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<Point> points;
  points.reserve(n);
  for (int i=0;i<n;++i) {
    long long int x, y;  std::cin >> x >> y;
    if (x<0) x*=-1;
    if (y<0) y*=-1;
    points.push_back(Point(x, y));
  }
  std::sort(points.begin(), points.end());

  std::vector<long long int> dp(n+1, INF);
  dp[0]=0;

  for (int i=1;i<=n;++i) {
    long long int max_y=0;
    for (int j=i;j>=1;--j) {
      max_y=std::max(max_y, points[j-1].y);
      long long int area=points[i-1].x*max_y<<2;
      if (dp[j-1]!=INF) dp[i]=std::min(dp[i], dp[j-1]+area);
    }
  }
  std::cout << dp[n];
  return 0;
}
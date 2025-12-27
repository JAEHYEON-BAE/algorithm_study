// 16095 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <cmath>
#include <iomanip>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

using ld=long double;

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}

  int operator-(const Point &o) const {
    return (x-o.x)*(x-o.x)+(y-o.y)*(y-o.y);
  }
};

bool isBipartite(const std::vector<std::vector<int>> &G)
{
  int n=G.size();
  std::queue<int> q;
  std::vector<int> color(n, 0);
  for (int i=0;i<n;++i) if (!color[i]) {
    q.push(i);
    color[i]=1;
    while (!q.empty()) {
      int u=q.front();
      q.pop();
      for (const int &v:G[u]) {
        if (color[v]==color[u]) return 0;
        else if (!color[v]) {
          color[v]=3-color[u];
          q.push(v);
        } 
      }
    }
  }
  return 1;
}

bool valid(int d, const std::vector<Point> &points) 
{
  int n=points.size();
  std::vector<std::vector<int>> G(n);
  for (int i=0;i<n;++i) for (int j=0;j<i;++j) {
    if (points[i]-points[j]>d) {
      // connect
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }
  for (int i=0;i<n;++i) if (G[i].size()==n-1) return 0;
  // connected graph must be bipartite graph
  return isBipartite(G);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::vector<Point> points(n);
    for (Point &p:points) std::cin >> p.x >> p.y;

    int l=0, r=8'000'010;

    int res=r;
    while (l<r) {
      int mid=(l+r)>>1;
      if (valid(mid, points)) {
        res=mid;
        r=mid;
      }
      else l=mid+1;
    }
    std::cout << std::fixed << std::setprecision(2) << std::ceil(std::sqrt(res)*100.0)/100.0 << '\n';
  }
  return 0;
}

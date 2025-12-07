// 1430

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

using ld=long double;

struct Tower
{
  int x, y;
  Tower() {}
  Tower(int x, int y): x(x), y(y) {}
};

inline bool in_range(const Tower &t1, const Tower &t2, const int &r) 
{
  return (t2.x-t1.x)*(t2.x-t1.x)+(t2.y-t1.y)*(t2.y-t1.y)<=r*r;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, r, d, x, y;  std::cin >> n >> r >> d >> x >> y;

  std::vector<std::vector<int>> G(n+1);
  std::vector<Tower> towers(n);
  for (int i=0;i<n;++i) {
    Tower &t=towers[i];
    std::cin >> t.x >> t.y;
    for (int j=0;j<i;++j) {
      if (in_range(t, towers[j], r)) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }

    if (in_range(t, Tower(x, y), r)) G[n].push_back(i);
  }

  std::vector<int> dist(n+1, -1);
  std::queue<int> q;
  q.push(n);  dist[n]=0;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const int &v:G[u]) if (dist[v]==-1) {
      dist[v]=1+dist[u];
      q.push(v);
    }
  }

  ld ans=0.0L;
  for (int i=0;i<n;++i) {
    ans+=static_cast<ld>(d)/(1LL<<(dist[i]-1));
  }
  std::cout << (ans<0.00001L?0:ans);
  return 0;
}

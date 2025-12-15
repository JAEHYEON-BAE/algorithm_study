// 1420 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl
constexpr int INF=(~0u)>>2;

struct Edge
{
  int to, rev, cap;
  Edge() {}
  Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
};

struct Dinic
{
  int n;
  std::vector<std::vector<Edge>> G;
  std::vector<int> level, iter;

  Dinic(int n): n(n), G(n), level(n), iter(n, 0) {}

  void add_edge(int u, int v, int c) {
    Edge a(v, G[v].size(), c);
    Edge b(u, G[u].size(), 0);

    G[u].push_back(a);
    G[v].push_back(b);
  }

  void BFS(int s) {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> q;
    level[s]=0;
    q.push(s);
    while (!q.empty()) {
      int u=q.front();
      q.pop();
      for (const auto &[v, _, c]:G[u]) if (c && level[v]==-1) {
        level[v]=1+level[u];
        q.push(v);
      }
    }
    return;
  }

  int DFS(int u, int t, int maxf) {
    if (u==t) return maxf;
    for (int &it=iter[u];it<G[u].size();++it) {
      auto &[v, r, c]=G[u][it];
      if (c && level[v]==1+level[u]) {
        int d=DFS(v, t, std::min(c, maxf));
        if (d) {
          c-=d;
          G[v][r].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int flow=0;
    while (1) {
      BFS(s);
      if (level[t]==-1) break;
      std::fill(iter.begin(), iter.end(), 0);
      while (int addf=DFS(s, t, INF)) flow+=addf;
    }
    return flow;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  Dinic d(n*m*2);

  int k, h;
  std::vector<std::string> city(n);
  for (int i=0;i<n;++i) {
    std::cin >> city[i];

    int u=i*m;
    for (int j=0;j<m;++j, ++u) if (city[i][j]!='#') {
      d.add_edge(u<<1, 1|u<<1, 1);
      if (i && city[i-1][j]!='#') {
        int v=u-m;
        d.add_edge(1|u<<1, v<<1, INF);
        d.add_edge(1|v<<1, u<<1, INF);
        // std::cerr << i-1 << ' ' << j << '\t' << i << ' ' << j << std::endl;
      }
      if (j && city[i][j-1]!='#') {
        int v=u-1;
        d.add_edge(1|u<<1, v<<1, INF);
        d.add_edge(1|v<<1, u<<1, INF);
        // std::cerr << i << ' ' << j-1 << '\t' << i << ' ' << j << std::endl;
      }

      if (city[i][j]=='K') k=u;
      else if (city[i][j]=='H') h=u;
    }
  }

  int kr=k/m, kc=k%m;
  int hr=h/m, hc=h%m;
  if (std::abs(kr-hr)+std::abs(kc-hc)==1) {
    std::cout << "-1";
    return 0;
  }
  else std::cout << d.max_flow(1|k<<1, h<<1);
  return 0;
}

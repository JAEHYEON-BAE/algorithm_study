// 11406

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

class Dinic
{
  struct Edge 
  {
    int to, rev, cap;
    Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
  };
  int n, m, k;
  std::vector<int> depth, it;
  std::vector<std::vector<Edge>> G;

  void add_edge(int u, int v, int c) {
    Edge a(v, G[v].size(), c);
    Edge b(u, G[u].size(), 0);
    G[u].push_back(a);
    G[v].push_back(b);
  }

  void BFS() {
    std::fill(depth.begin(), depth.end(), -1);
    depth[0]=0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u=q.front();  q.pop();
      for (const Edge &e:G[u]) if (e.cap && depth[e.to]==-1) {
        depth[e.to]=1+depth[u];
        q.push(e.to);
      }
    }
  }

  int DFS(int u, int t, int maxf) {
    if (u==t) return maxf;
    for (int &i=it[u];i<G[u].size();++i) {
      Edge &e=G[u][i];
      if (e.cap && depth[e.to]==1+depth[u]) {
        int flow=DFS(e.to, t, std::min(maxf, e.cap));
        if (flow) {
          e.cap-=flow;
          G[e.to][e.rev].cap+=flow;
          return flow;
        }
      }
    }
    return 0;
  }

public:
  Dinic(int n, int m): n(n), m(m), k(n+m+2) {
    // SOURCE= 0, SINK= n+m+1
    // store= 1 ~ m, person= m+1 ~ m+n

    depth.resize(k);
    it.assign(k, 0);
    G.resize(k);

    for (int i=0;i<n;++i) {
      int x;  std::cin >> x;
      add_edge(m+1+i, k-1, x);
    }
    for (int i=0;i<m;++i) {
      int x;  std::cin >> x;
      add_edge(0, 1+i, x);
    }
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
      int x;  std::cin >> x;
      if (x) add_edge(1+i, m+1+j, x);
    }
  }

  int max_flow() {
    int flow=0;
    while (1) {
      BFS();
      if (depth[k-1]==-1) break;
      std::fill(it.begin(), it.end(), 0);
      while (int f=DFS(0, k-1, (~0u)>>1)) flow+=f;
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
  Dinic x(n, m);

  std::cout << x.max_flow();
  return 0;
}
// 17412

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
    int to, rev;
    bool cap;
    Edge(int t, int r, bool c): to(t), rev(r), cap(c) {}
  };

  int n;
  std::vector<int> depth, it;
  std::vector<std::vector<Edge>> G;

  void add_edge(int u, int v) {
    Edge a(v, G[v].size(), 1);
    Edge b(u, G[u].size(), 0);
    G[u].push_back(a);
    G[v].push_back(b);
  }

  void BFS() {
    std::fill(depth.begin(), depth.end(), -1);
    std::queue<int> q;
    depth[0]=0;
    q.push(0);
    while (!q.empty()) {
      int u=q.front();  q.pop();
      for (const Edge &e:G[u]) if (e.cap && depth[e.to]==-1) {
        depth[e.to]=1+depth[u];
        q.push(e.to);
      }
    }
    return;
  }

  bool DFS(int u, int t) {
    if (u==t) return 1;
    for (int &i=it[u];i<G[u].size();++i) {
      Edge &e=G[u][i];
      if (e.cap && depth[e.to]==1+depth[u]) {
        bool flow=DFS(e.to, t);
        if (flow) {
          e.cap=0;
          G[e.to][e.rev].cap=1;
          return 1;
        }
      }
    }
    return 0;
  }


public:
  Dinic(int n, int p): n(n) {
    depth.resize(n);
    it.resize(n);
    G.resize(n);
    for (int i=0;i<p;++i) {
      int u, v;  std::cin >> u >> v;
      add_edge(u-1, v-1);
    }
  }

  int max_flow() {
    int flow=0;
    while (1) {
      BFS();
      if (depth[1]==-1) break;
      std::fill(it.begin(), it.end(), 0);
      while (DFS(0, 1)) ++flow;
    }
    return flow;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, p;  std::cin >> n >> p;
  Dinic x(n, p);
  std::cout << x.max_flow();

  return 0;
}
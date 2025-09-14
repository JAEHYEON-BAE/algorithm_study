// 11407

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int INF=(~0u)>>1;

struct Edge
{
  int to, rev, cap, cost;
  Edge(int t, int r, int c, int cost): to(t), rev(r), cap(c), cost(cost) {}
};

class MCMF
{
  int n, m;
  int k;
  std::vector<std::vector<Edge>> graph;
  std::vector<int> dist, poten, pv, pe;

  // SOURCE=0, SINK=m+n+1
  void add_edge(int u, int v, int cap, int cost) {
    Edge a(v, graph[v].size(), cap, cost);
    Edge b(u, graph[u].size(), 0, -cost);
    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  std::pair<int, int> mcmf() {
    int flow=0, cost=0;

    int s=0, t=k-1;
    int maxf=INF;
    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[s]=0;
      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
      pq.push({0, s});
      while (!pq.empty()) {
        auto [d, u]=pq.top();  pq.pop();
        if (dist[u]<d) continue;
        for (int i=0;i<graph[u].size();++i) {
          Edge &e=graph[u][i];
          if (e.cap) {
            int nd=dist[u]+e.cost+poten[u]-poten[e.to];
            if (nd<dist[e.to]) {
              dist[e.to]=nd;
              pv[e.to]=u;
              pe[e.to]=i;
              pq.push({nd, e.to});
            }
          }
        }
      }
      if (dist[t]==INF) break;
      for (int i=0;i<k;++i) if (dist[i]<INF) poten[i]+=dist[i];
      int addf=maxf-flow;
      for (int i=t;i!=s;i=pv[i]) addf=std::min(addf, graph[pv[i]][pe[i]].cap);
      
      flow+=addf;
      cost+=addf*poten[t];

      for (int i=t;i!=s;i=pv[i]) {
        Edge &e=graph[pv[i]][pe[i]];
        e.cap-=addf;
        graph[i][e.rev].cap+=addf;
      }
    }
    return {flow, cost};
  }

public:
  MCMF(int n, int m): n(n), m(m), k(n+m+2) {
    graph.resize(k);
    dist.resize(k);
    poten.assign(k, 0);
    pv.resize(k);
    pe.resize(k);
    for (int i=0;i<n;++i) {
      int x;  std::cin >> x;
      add_edge(m+1+i, m+n+1, x, 0);
    }
    for (int i=0;i<m;++i) {
      int x;  std::cin >> x;
      add_edge(0, 1+i, x, 0);
    }
    
    std::vector<std::vector<int>> c(m, std::vector<int>(n)), d(m, std::vector<int>(n));
    for (auto &r:c) for (int &x:r) std::cin >> x;
    for (auto &r:d) for (int &x:r) std::cin >> x;

    for (int i=0;i<m;++i) for (int j=0;j<n;++j) if (c[i][j]) {
      add_edge(1+i, m+1+j, c[i][j], d[i][j]);
    }
  }
  void solve() {
    auto [flow, cost]=mcmf();
    std::cout << flow << '\n' << cost;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  MCMF x(n, m);

  x.solve();
 
  return 0;
}
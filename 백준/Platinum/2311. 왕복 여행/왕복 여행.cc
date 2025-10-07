// 2311

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int INF=(~0u)>>2;

struct Edge
{
  int to, rev, cap, weight;
  Edge() {}
  Edge(int t, int r, int c, int w): to(t), rev(r), cap(c), weight(w) {}
};

class MCMF
{
  int n;
  std::vector<std::vector<Edge>> G;


public:
  MCMF(int n): n(n), G(n) {}

  void add_edge(int u, int v, int w) {
    Edge a(v, G[v].size(), 1, w);
    Edge b(u, G[u].size(), 0, -w);

    G[u].push_back(a);
    G[v].push_back(b);
  }

  int time() {
    int maxf=2, cost=0;

    int S=0, T=n-1;

    int flow=0;
    std::vector<int> dist(n, INF), poten(n, 0), pv(n), pe(n);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    
    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[S]=0;
      
      pq.push({0, S});

      while (!pq.empty()) {
        auto [d, u]=pq.top();
        pq.pop();
        if (dist[u]<d) continue;
        for (int i=0;i<G[u].size();++i) if (G[u][i].cap) {
          Edge &e=G[u][i];
          int nd=d+e.weight+poten[u]-poten[e.to];
          if (dist[e.to]>nd) {
            dist[e.to]=nd;
            pv[e.to]=u;
            pe[e.to]=i;
            pq.push({nd, e.to});
          }
        }
      }
      if (dist[T]==INF) break;
      for (int i=0;i<n;++i) poten[i]+=dist[i];
      int addf=maxf-flow;
      for (int i=T;i!=S;i=pv[i]) addf=std::min(addf, G[pv[i]][pe[i]].cap);
      flow+=addf;
      cost+=addf*poten[T];
      for (int i=T;i!=S;i=pv[i]) {
        Edge &e=G[pv[i]][pe[i]];
        e.cap-=addf;
        G[i][e.rev].cap+=addf;
      }
    }
    return cost;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  MCMF x(n);
  for (int _=0;_<m;++_) {
    int a, b, c;  std::cin >> a >> b >> c;
    --a;--b;
    x.add_edge(a, b, c);
    x.add_edge(b, a, c);
  }
  std::cout << x.time();
  return 0;
}
// 9413

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

constexpr int INF=(~0u)>>1;

struct Edge
{
  int to, rev, cap, weight;
  Edge() {}
  Edge(int t, int r, int c, int w): to(t), rev(r), cap(c), weight(w) {}
};

struct DAG
{
  int n;
  std::vector<std::vector<Edge>> G;
  std::vector<int> dist, pv, pe, poten;

  // SOURCE: 0, SINK: 1
  DAG(int n): n(n), G(n), dist(n), poten(n, 0), pv(n), pe(n) {}

  void add_edge(int u, int v, int w) {
    Edge a(v, G[v].size(), 1, w);
    Edge b(u, G[u].size(), 0, -w);

    G[u].push_back(a);
    G[v].push_back(b);
  }

  std::pair<int, int> mcmf() {
    int flow=0, cost=0;

    int s=0, t=1;
    int maxf=2;

    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[s]=0;
      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
      pq.push({0, s});
      while (!pq.empty()) {
        auto [d, u]=pq.top();
        pq.pop();
        if (dist[u]<d) continue;
        for (int i=0;i<G[u].size();++i) {
          Edge &e=G[u][i];
          if (e.cap) {
            int nd=dist[u]+e.weight+poten[u]-poten[e.to];
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
      for (int i=0;i<n;++i) if (dist[i]<INF) poten[i]+=dist[i];
      int addf=maxf-flow;
      for (int i=t;i!=s;i=pv[i]) addf=std::min(addf, G[pv[i]][pe[i]].cap);
      flow+=addf;
      cost+=addf*poten[t];
      for (int i=t;i!=s;i=pv[i]) {
        Edge &e=G[pv[i]][pe[i]];
        e.cap-=addf;
        G[i][e.rev].cap+=addf;
      }
    }
    return {flow, cost};
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, m;  std::cin >> n >> m;
    DAG dag((n+1)<<1);
    for (int i=1;i<=n;++i) {
      dag.add_edge(0, i<<1, 0);
      dag.add_edge(i<<1, 1|i<<1, -1);
      dag.add_edge(1|i<<1, 1, 0);
    }
    while (m--) {
      int a, b;  std::cin >> a >> b;
      dag.add_edge(1|a<<1, b<<1, 0);
    }
    std::cout << -dag.mcmf().second << '\n';
  }
  return 0;
}

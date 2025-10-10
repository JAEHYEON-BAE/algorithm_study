// 11405

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
  Edge(int t, int r, int c, int w): to(t), rev(r), cap(c), weight(w) {}
};

class MCMF
{
  int k;
  std::vector<std::vector<Edge>> G;

  void add_edge(int u, int v, int cap, int weight) {
    Edge a(v, G[v].size(), cap, weight);
    Edge b(u, G[u].size(), 0, -weight);

    G[u].push_back(a);
    G[v].push_back(b);
  }
public:
  MCMF(int n, int m, const std::vector<int> &a, const std::vector<int> &b, const std::vector<std::vector<int>> &c): k(n+m+2) {
    G.resize(k);
    for (int i=1;i<=m;++i) {
      add_edge(0, i, b[i-1], 0);
      for (int j=m+1;j<=m+n;++j) add_edge(i, j, b[i-1], c[i-1][j-m-1]);
    }
    for (int i=m+1;i<=m+n;++i) add_edge(i, k-1, a[i-m-1], 0);
  }

  int min_cost() {
    std::vector<int> dist(k), pv(k), pe(k), poten(k, 0);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    int cost=0, flow=0, maxf=INF;
    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      pq.push({0, 0});
      dist[0]=0;

      while (!pq.empty()) {
        const auto [d, u]=pq.top();
        pq.pop();
        if (dist[u]<d) continue;
        for (int i=0;i<G[u].size();++i) if (G[u][i].cap) {
          const Edge &e=G[u][i];
          int nd=d+e.weight+poten[u]-poten[e.to];
          if (dist[e.to]>nd) {
            dist[e.to]=nd;
            pv[e.to]=u;
            pe[e.to]=i;
            pq.push({nd, e.to});
          }
        }
      }
      if (dist[k-1]==INF) break;
      for (int i=0;i<k;++i) poten[i]+=dist[i];
      int addf=maxf-flow;
      for (int i=k-1;i!=0;i=pv[i]) addf=std::min(addf, G[pv[i]][pe[i]].cap);
      flow+=addf;
      cost+=addf*poten[k-1];
      for (int i=k-1;i!=0;i=pv[i]) {
        Edge &e=G[pv[i]][pe[i]];
        e.cap-=addf;
        G[e.to][e.rev].cap+=addf;
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
  std::vector<int> a(n), b(m);
  std::vector<std::vector<int>> c(m, std::vector<int>(n));
  for (int &x:a) std::cin >> x;
  for (int &x:b) std::cin >> x;
  for (auto &v:c) for (int &x:v) std::cin >> x;

  MCMF mcmf(n, m, a, b, c);
  std::cout << mcmf.min_cost();

  return 0;
}
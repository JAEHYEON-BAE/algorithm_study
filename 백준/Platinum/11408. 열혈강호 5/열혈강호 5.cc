// 11408

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

// SOURCE=0, EMPLOYEE=1~N, WORK=N+1~N+M, SINK=N+M+1
class MCMF
{
  int k;
  std::vector<std::vector<Edge>> G;
  std::vector<int> poten, pv, pe;

#define SOURCE 0
#define SINK k-1

public:
  MCMF(int n, int m): k(n+m+2) {
    G.resize(k);
    poten.assign(k, 0);
    pv.resize(k), pe.resize(k);
    for (int i=1;i<=n;++i) add_edge(SOURCE, i, 0);
    for (int i=n+1;i<=n+m;++i) add_edge(i, SINK, 0);
  }

  void add_edge(int u, int v, int w) {
    Edge a(v, G[v].size(), 1, w);
    Edge b(u, G[u].size(), 0, -w);
    
    G[u].push_back(a);
    G[v].push_back(b);
  }

  std::pair<int, int> mcmf() {
    int flow=0, w=0;
    int maxf=INF;

    std::vector<int> dist(k);

    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[SOURCE]=0;
      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
      pq.push({0, SOURCE});

      while (!pq.empty()) {
        auto [d, u]=pq.top();
        pq.pop();
        if (dist[u]<d) continue;

        for (int i=0;i<G[u].size();++i) if (G[u][i].cap) {
          Edge &e=G[u][i];
          int nd=dist[u]+e.weight+poten[u]-poten[e.to];
          if (nd<dist[e.to]) {
            dist[e.to]=nd;
            pv[e.to]=u;
            pe[e.to]=i;
            pq.push({nd, e.to});
          }
        }
      }
      if (dist[SINK]==INF) break;

      for (int i=0;i<k;++i) if (dist[i]<INF) poten[i]+=dist[i];
      int add_flow=maxf-flow;
      for (int i=SINK;i!=SOURCE;i=pv[i]) add_flow=std::min(add_flow, G[pv[i]][pe[i]].cap);
      
      flow+=add_flow;
      w+=add_flow*poten[SINK];
      for (int i=SINK;i!=SOURCE;i=pv[i]) {
        Edge &e=G[pv[i]][pe[i]];
        e.cap-=add_flow;
        G[i][e.rev].cap+=add_flow;
      }
    }
    return std::make_pair(flow, w);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  MCMF prob(n, m);
  for (int i=0;i<n;++i) {
    int k;  std::cin >> k;
    for (int j=0;j<k;++j) {
      int x, c;  std::cin >> x >> c;
      --x;
      prob.add_edge(i+1, x+n+1, c);
    }
  }
  const auto ans=prob.mcmf();
  std::cout << ans.first << '\n' << ans.second;
  return 0;
}
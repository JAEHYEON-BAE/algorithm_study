// 1258

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

struct MCMF
{
  int k;
  std::vector<std::vector<Edge>> G;

  void add_edge(int u, int v, int c, int w) {
    Edge a(v, G[v].size(), c, w);
    Edge b(u, G[u].size(), 0, -w);
    G[u].push_back(a);
    G[v].push_back(b);
  }

  // SOURCE=0, STUDENT=1~n, PROBLEM=n+1~2n, SINK=2n+1
  MCMF(int n, const std::vector<std::vector<int>> &v): k(n+1<<1) {
    G.resize(k);
    for (int i=1;i<=n;++i) add_edge(0, i, 1, 0), add_edge(n+i, k-1, 1, 0);
    
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
      add_edge(1+i, n+1+j, 1, v[i][j]);
    }
  }

  int min_cost() {
    std::vector<int> poten(k, 0), pv(k), pe(k), dist(k);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    int maxf=(~0u)>>1, cost=0, flow=0;
    while (flow<maxf) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[0]=0;
      pq.push({0, 0});
      while (!pq.empty()) {
        auto [d, u]=pq.top();
        pq.pop();
        if (dist[u]<d) continue;
        for (int i=0;i<G[u].size();++i) if (G[u][i].cap) {
          Edge &e=G[u][i];
          int nd=d+e.weight+poten[u]-poten[e.to];
          if (nd<dist[e.to]) {
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

  int n;  std::cin >> n;
  
  // v[i][j] := 학생 i가 j번 문제를 푸는 데 걸리는 시간
  std::vector<std::vector<int>> v(n, std::vector<int>(n));
  for (auto &r:v) for (int &x:r) std::cin >> x;

  MCMF mcmf(n, v);
  std::cout << mcmf.min_cost();
  
  return 0;
}
// 3640

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

constexpr int INF=(~0u)>>2;

struct Edge
{
  int to, rev, cap, cost;
  Edge() {}
  Edge(int to, int rev, int cap, int cost): to(to), rev(rev), cap(cap), cost(cost) {}
};

inline void add_edge(int u, int v, int cap, int cost, std::vector<std::vector<Edge>> &graph)
{
  graph[u].push_back(Edge(v, graph[v].size(), cap, cost));
  graph[v].push_back(Edge(u, graph[u].size()-1, 0, -cost));
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int v, e;
  while (std::cin >> v >> e) {
    // 각 노드 번호에 i에 대해서, i<<1 := i_in, i<<1|1 := i_out
    int n=v<<1;
    std::vector<std::vector<Edge>> graph(n);
    for (int i=1;i<v-1;++i) add_edge(i<<1, i<<1|1, 1, 0, graph);

    add_edge(0, 1, 2, 0, graph);
    add_edge((v-1)<<1, (v-1)<<1|1, 2, 0, graph);
    
    for (int _=0;_<e;++_) {
      int a, b, c;  std::cin >> a >> b >> c;
      --a,--b;
      add_edge(a<<1|1, b<<1, 1, c, graph);
    }


    int flow=0, cost=0;
    int S=0, T=(v-1)<<1|1;

    std::vector<int> h(n, 0), dist(n), prev_v(n), prev_e(n);

    while (flow<2) {
      std::fill(dist.begin(), dist.end(), INF);
      dist[S]=0;

      using p=std::pair<int, int>;
      std::priority_queue<p, std::vector<p>, std::greater<p>> pq;

      pq.push({0, S});

      while (!pq.empty()) {
        auto [d, curr]=pq.top();
        pq.pop();
        if (d!=dist[curr]) continue;

        for (int i=0;i<graph[curr].size();++i) {
          Edge &edge=graph[curr][i];
          if (edge.cap<=0) continue;

          int nd=dist[curr]+edge.cost+h[curr]-h[edge.to];

          if (dist[edge.to]>nd) {
            dist[edge.to]=nd;
            prev_v[edge.to]=curr;
            prev_e[edge.to]=i;
            pq.push({nd, edge.to});
          }
        }
      }

      if (dist[T]==INF) break;

      for (int i=0;i<n;++i) if (dist[i]<INF) h[i]+=dist[i];

      int d=2-flow;
      for (int i=T;i!=S;i=prev_v[i]) {
        d=std::min(d, graph[prev_v[i]][prev_e[i]].cap);
      }
      for (int i=T;i!=S;i=prev_v[i]) {
        Edge &edge=graph[prev_v[i]][prev_e[i]];
        edge.cap-=d;
        graph[i][edge.rev].cap+=d;
      }
      flow+=d;
      cost+=d*h[T];
    }

    std::cout << cost << '\n';
  }

  return 0;
}
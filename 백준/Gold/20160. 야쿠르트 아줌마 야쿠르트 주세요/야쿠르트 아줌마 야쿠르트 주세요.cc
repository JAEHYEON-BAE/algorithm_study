// 20160

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr int INF=(~0u)>>2;

struct Edge
{
  int to, w;
  Edge() {}
  Edge(int t, int w): to(t), w(w) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int v, e;  std::cin >> v >> e;
  std::vector<std::vector<Edge>> G(v);
  for (int _=0;_<e;++_) {
    int u, v, w;  std::cin >> u >> v >> w;
    --u, --v;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }

  std::vector<ll> ytime(v, -1);
  int prev;  std::cin >> prev;  --prev;
  ytime[prev]=0;
  for (int i=0;i<9;++i) {
    int curr;  std::cin >> curr;  --curr;
    
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
    std::vector<ll> dist(v, INF);
    pq.push({0, prev});
    dist[prev]=0;

    while (!pq.empty()) {
      auto [xd, x]=pq.top();
      pq.pop();
      if (dist[x]<xd) continue;
      if (x==curr) break;
      for (const auto &[y, d]:G[x]) {
        if (xd+d<dist[y]) {
          dist[y]=xd+d;
          pq.push({dist[y], y});
        }
      }
    }
    
    if (dist[curr]<INF) {
      ytime[curr]=ytime[prev]+dist[curr];
      prev=curr;
    }
    else continue;
  }

  int s;  std::cin >> s;  --s;
  
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
  std::vector<int> dist(v, INF);
  pq.push({0, s});
  dist[s]=0;

  while (!pq.empty()) {
    auto [xd, x]=pq.top();
    pq.pop();
    if (dist[x]<xd) continue;
    for (const auto &[y, d]:G[x]) {
      if (xd+d<dist[y]) {
        dist[y]=xd+d;
        pq.push({dist[y], y});
      }
    }
  }

  for (int i=0;i<v;++i) {
    if (ytime[i]==-1 || dist[i]==INF) continue;
    if (dist[i]<=ytime[i]) {
      std::cout << i+1;
      return 0;
    }
  }
  std::cout << "-1";
  return 0;
}
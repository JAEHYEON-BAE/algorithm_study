// 1761

#include <iostream>
#include <vector>
#include <unordered_map>

#define debug(a) std::cout << "CHECKPOINT #" << a << std::endl

void DFS(int curr, int prev, int d, int w, const std::unordered_map<int, int> (&graph)[40001], int (&parent)[40001][16], int (&depth)[40001], int (&dist)[40001]) 
{

  depth[curr] = d;
  dist[curr] = w;
  parent[curr][0] = prev;
  for (int i=1;i<16;++i) {
    parent[curr][i] = parent[parent[curr][i-1]][i-1];
  }
  for (auto& next: graph[curr]) {
    if (next.first!=prev) {
      DFS(next.first, curr, d+1, w+next.second, graph, parent, depth, dist);
    }
  }
}

int LCA(int a, int b, const std::unordered_map<int, int> (&graph)[40001], const int (&parent)[40001][16], const int (&depth)[40001], const int (&dist)[40001])
{
  if (depth[a]<depth[b]) std::swap(a, b);

  for (int i=15;i>=0;--i) {
    if (depth[a]-(1<<i)>=depth[b]) a=parent[a][i];
  }

  if (a==b) return a;

  for (int i=15;i>=0;--i) {
    if (parent[a][i]!=parent[b][i]) {
      a = parent[a][i];
      b = parent[b][i];
    }
  }

  return parent[a][0];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n;  std::cin >> n;
  std::unordered_map<int, int> graph[40001];
  int parent[40001][16];
  int depth[40001];
  int dist[40001];
  
  for (int i=0;i<n-1;++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u;  --v;
    graph[u][v] = w;  graph[v][u] = w;
  }

  DFS(0, 0, 0, 0, graph, parent, depth, dist);
  
  int m;  std::cin >> m;
  while (m--) {
    int u, v;  std::cin >> u >> v;
    --u;  --v;
    std::cout << dist[u]+dist[v]-2*dist[LCA(u, v, graph, parent, depth, dist)] << '\n';
  }
  
  return 0;  
}

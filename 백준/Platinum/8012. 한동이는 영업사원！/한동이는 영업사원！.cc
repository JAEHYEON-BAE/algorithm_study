// 8012

#include <iostream>
#include <vector>
#include <algorithm>

#define debug(a) std::cerr << "CHECKPOINT #" << a << std::endl

void DFS(int curr, int prev, int d, const int &n,
const std::vector<std::vector<int>> &graph, 
std::vector<std::vector<int>> &parent, 
std::vector<int> &depth)
{
  parent[curr][0] = prev;
  depth[curr] = d;

  for (int i=1;(1<<i)<n;++i) {
    parent[curr][i] = parent[parent[curr][i-1]][i-1];
  }
  for (const int& next: graph[curr]) {
    if (next==prev) continue;
    DFS(next, curr, d+1, n, graph, parent, depth);
  }  
}

int shortest_path(int u, int v, const int &n,
const std::vector<std::vector<int>> &graph, 
std::vector<std::vector<int>> &parent, 
std::vector<int> &depth)
{
  if (u==v) return 0;
  
  if (depth[u]<depth[v]) std::swap(u, v);

  int result = depth[u]+depth[v];

  for (int i=15;i>=0;--i) {
    if (depth[u] - (1<<i) >= depth[v]) u=parent[u][i];
  }

  if (u==v) {
    // calculate shortest path
    result -= 2*depth[u];
    return result;
  }

  for (int i=15;i>=0;--i) {
    if (parent[u][i]!=parent[v][i]) {
      u=parent[u][i];
      v=parent[v][i];
    }
  }
  u=parent[u][0];
  v=parent[v][0];

  result -= 2*depth[u];
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> graph(n), parent(n, std::vector<int>(16));
  std::vector<int> depth(n);
  for (int i=0;i<n-1;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  DFS(0, 0, 0, n, graph, parent, depth);
  int m;  std::cin >> m;

  int result = 0;
  int prev = 0;
  while (m--) {
    int u;  std::cin >> u;
    --u;
    result += shortest_path(prev, u, n, graph, parent, depth);
    prev = u;
  }
  std::cout << result;
  
  return 0;  
}

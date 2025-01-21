// 3176

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define debug(a) std::cout << "CHECKPOINT #" << a << std::endl
#define N 100001
#define LOG 17

std::unordered_map<int, int> graph[N];
int parent[N][LOG];
int depth[N];
int max[N][LOG];
int min[N][LOG];

void DFS(int curr, int prev, int d, int w)
{
  parent[curr][0] = prev;
  depth[curr] = d;
  max[curr][0] = w;
  min[curr][0] = w;
  
  for (int i=1;i<LOG;++i) {
    int mid = parent[curr][i-1];
    if (mid==-1) {
      parent[curr][i] = -1;
      max[curr][i] = -1;
      min[curr][i] = (~0u)>>1;
      continue;
    }

    parent[curr][i] = parent[mid][i-1];
    if (parent[curr][i]==-1) {
      max[curr][i] = -1;
      min[curr][i] = (~0u)>>1;
      continue;
    }
    max[curr][i] = std::max(max[curr][i-1], max[mid][i-1]);
    min[curr][i] = std::min(min[curr][i-1], min[mid][i-1]);
  }

  for (auto &next: graph[curr]) {
    if (next.first!=prev) {
      DFS(next.first, curr, d+1, next.second);
    }
  }
}

void query(int u, int v) 
{
  if (depth[u]<depth[v]) std::swap(u, v);

  int max_edge = -1, min_edge = (~0u)>>1;
  for (int i=LOG-1;i>=0;--i) {
    if (depth[u]-(1<<i)>=depth[v]) {
      max_edge = std::max(max_edge, max[u][i]);
      min_edge = std::min(min_edge, min[u][i]);
      u = parent[u][i];
    }
  }

  if (u==v) {
    std::cout << min_edge << ' ' << max_edge << '\n';
    return;
  }

  for (int i=LOG-1;i>=0;--i) {
    if (parent[u][i]!=-1 && parent[u][i]!=parent[v][i]) {
      max_edge = std::max(max_edge, std::max(max[u][i], max[v][i]));
      min_edge = std::min(min_edge, std::min(min[u][i], min[v][i]));
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  max_edge = std::max(max_edge, std::max(max[u][0], max[v][0]));
  min_edge = std::min(min_edge, std::min(min[u][0], min[v][0]));

  std::cout << min_edge << ' ' << max_edge << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  for (int i=0;i<n-1;++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u;  --v;
    graph[u][v] = w;  graph[v][u] = w;
  }
  
  DFS(0, -1, 0, 0);
  
  int k;  std::cin >> k;
  while (k--) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    query(u, v);
  }
  
  return 0;  
}

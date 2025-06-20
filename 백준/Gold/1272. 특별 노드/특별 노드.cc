// 1272

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

class DP_DFS
{
  const int &n;
  const int &root;
  const std::vector<int> &w;
  const std::vector<std::vector<int>> &graph;
  std::vector<std::vector<int>> dp;
  std::vector<bool> visited;

  int DFS(int curr, int last) {
    if (dp[curr][last]!=-1) return dp[curr][last];

    int norm=w[curr]-w[last];
    int spec=w[curr];
    visited[curr]=1;
    for (const int &next:graph[curr]) if (!visited[next]) {
      spec+=DFS(next, curr);
      norm+=DFS(next, last);
    }
    visited[curr]=0;
    if (curr==root) return dp[curr][last]=spec;
    return dp[curr][last]=std::min(spec, norm);
  }

public:
  DP_DFS(const int &n, const int &root, const std::vector<int> &w, const std::vector<std::vector<int>> &graph): n(n), root(root), w(w), graph(graph) {
    dp.assign(n, std::vector<int>(n, -1));
    visited.assign(n, 0);
  }
  int solve() {
    return DFS(root, root);
  }

};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, root;  std::cin >> n >> root;
  --root;
  std::vector<int> w(n);
  int tot=0;
  std::vector<std::vector<int>> graph(n);
  for (int i=0;i<n;++i) {std::cin >> w[i]; tot+=w[i];}
  
  for (int i=0;i<n-1;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

  DP_DFS x(n, root, w, graph);
  std::cout << x.solve();

  return 0;
}

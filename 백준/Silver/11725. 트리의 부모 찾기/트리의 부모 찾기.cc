// 11725
#include <iostream>
#include <vector>
#include <cassert>

void BFS(int curr, int prev, const std::vector<std::vector<int>> &graph, std::vector<int> &parent)
{
  for (const int& neighbor: graph[curr]) {
    if (neighbor==prev) continue;
    parent[neighbor]=curr;
    BFS(neighbor, curr, graph, parent);
  }
}

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> graph(n+1);
  for (int i=0;i<n;++i) {
    int u, v;  std::cin >> u >> v;
    graph[u].push_back(v);  graph[v].push_back(u);
  }
  std::vector<int> parent(n+1, -1);
  BFS(1, -1, graph, parent);
  for (int i=2;i<n+1;++i) {
    std::cout << parent[i] << '\n';
  }
  
 
  return 0; 
}

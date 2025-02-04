// 1766

#include <iostream>
#include <vector>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  /** priority_queue: 
    *   1. lower in-degree first
    *   2. lower difficulty first
    */
  std::vector<std::vector<int>> graph(n+1);
  std::vector<int> in_degree(n+1, 0);
  std::vector<int> result;
  int a, b;
  for (int i=0;i<m;++i) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    ++in_degree[b];
  }
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i=1;i<=n;++i) {
    if (in_degree[i]==0) pq.push(i);
  }
  while (!pq.empty()) {
    int curr=pq.top();
    pq.pop();
    result.push_back(curr);
    for (const int& next: graph[curr]) {
      if (--in_degree[next]==0) pq.push(next);
    }
  }

  for (int &x:result) std::cout << x << ' ';
  
  return 0; 
}

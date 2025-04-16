// 25333
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::unordered_set<int>> map(n);
  for (int i=0;i<m;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    map[u].insert(v);
    map[v].insert(u);
  }
  std::vector<int> army(n);
  for (int i=0;i<n;++i) std::cin >> army[i];

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  std::vector<bool> visited(n, 0);
  pq.push({army[0], 0});
  int size=0;
  visited[0]=1;

  bool FLAG=0;
  while (!pq.empty()) {
    if (FLAG && size<=pq.top().first) break;
    FLAG=1;
    int curr=pq.top().second;
    size+=pq.top().first;
    pq.pop();
    for (const int &next:map[curr]) {
      if (visited[next]) continue;
      pq.push({army[next], next});
      visited[next]=1;
    }
  }

  std::cout << size;
  return 0;
}
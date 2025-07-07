// 2637

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  // 0 ~ n-2 : middle part
  // n-1 : finished product

  std::vector<std::unordered_map<int, int>> graph(n);
  std::vector<int> in_degree(n, 0);
  for (int i=0;i<m;++i) {
    int x, y, k;  std::cin >> x >> y >> k;
    --x;--y;
    graph[x][y]=k;
    ++in_degree[y];
  }

  std::queue<int> q;
  q.push(n-1);

  std::vector<int> needed(n, 0);
  needed[n-1]=1;

  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    bool IS_MIDDLE=0;
    for (const auto &[next, k]:graph[curr]) {
      IS_MIDDLE=1;
      needed[next]+=needed[curr]*k;
      if (!--in_degree[next]) q.push(next);
    }
    if (IS_MIDDLE) needed[curr]=0;
  }

  for (int i=0;i<n;++i) if (needed[i]) {
    std::cout << i+1 << ' ' << needed[i] << '\n';
  }
  
  return 0;
}
// 11726

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> G(n);
  for (int i=0;i<m;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  std::vector<bool> visited(n, 0);
  int cnt=0;
  while (1) {
    int s=-1;
    for (int i=0;i<n;++i) if (!visited[i]) {
      s=i; break;
    }
    if (s==-1) break;

    std::queue<int> q;
      
    q.push(s);
    visited[s]=1;
    
    while (!q.empty()) {
      int curr=q.front();
      q.pop();
      for (const int &next:G[curr]) if (!visited[next]) {
        q.push(next);
        visited[next]=1;
      }
    }
    ++cnt;
  }
  std::cout << cnt;
  return 0;
}
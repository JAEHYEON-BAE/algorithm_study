// 27924
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

constexpr int INF=(~0u)>>1;
constexpr int nINF=(1<<31);
constexpr int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

std::vector<int> BFS(const int &s, const std::vector<std::vector<int>> &map)
{
  // DEBUG(s);
  std::vector<int> distance(map.size());
  std::vector<bool> visited(map.size(), 0);
  std::queue<int> q;
  q.push(s);
  distance[s]=0;
  visited[s]=1;

  bool _u=0, _d=0, _p=0;
  while (!q.empty()) {
    int curr=q.front();
    q.pop();

    for (const int &next: map[curr]) {
      if (visited[next]) continue;
      visited[next]=1;
      distance[next]=1+distance[curr];
      q.push(next);
    }
  }
  return distance;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<std::vector<int>> map(n);
  for (int i=0;i<n-1;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    map[u].push_back(v);
    map[v].push_back(u);
  }
  int u, d, p;  std::cin >> u >> d >> p;
  --u; --d; --p;

  std::vector<int> _from_u=BFS(u, map), _from_d=BFS(d, map), _from_p=BFS(p, map);

  for (int i=0;i<n;++i) if (map[i].size()==1) {
    if (i==u) {
      std::cout << "YES"; return 0;
    }
    if (_from_u[i]<_from_d[i] && _from_u[i]<_from_p[i]) {
      std::cout << "YES"; return 0;
    }
  }
  std::cout << "NO";
  return 0;
}
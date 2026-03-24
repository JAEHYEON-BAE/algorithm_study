// 34856

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

std::pair<int, int> DFS(int u, int p, const std::vector<std::vector<int>> &tree, std::vector<int> &dist, std::vector<bool> &visited)
{
  int idx=u, len=dist[u];
  visited[u]=1;

  for (const int &v:tree[u]) if (v!=p) {
    dist[v]=1+dist[u];
    const auto pair=DFS(v, u, tree, dist, visited);
    if (pair.second>len) {
      idx=pair.first;
      len=pair.second;
    }
  }
  return std::make_pair(idx, len);
}

struct PairHash {
  size_t operator()(const std::pair<int,int>& p) const {
    return std::hash<long long>()(((long long)p.first<<32)|p.second);
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::unordered_set<std::pair<int, int>, PairHash> s;
  for (int i=0;i<n-1;++i) {
    int u, v; std::cin >> u >> v;
    --u, --v;
    if (u>v) std::swap(u, v);
    s.insert(std::make_pair(u, v));
  }

  std::vector<std::vector<int>> tree(n);
  for (int i=0;i<n-1;++i) {
    int u, v; std::cin >> u >> v;
    --u, --v;
    if (u>v) std::swap(u, v);
    if (s.count(std::make_pair(u, v))) {
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
  }

  std::vector<bool> visited(n, 0);
  std::vector<int> dist(n, 0);

  int bestLen=0, bestU=-1, bestV=-1;

  for (int i=0;i<n;++i) if (!visited[i] && !tree[i].empty()) {
    // DFS 1
    dist[i]=0;
    auto [u, d1]=DFS(i, -1, tree, dist, visited);

    // DFS 2
    std::vector<int> dist2(n, 0);
    dist2[u]=0;
    auto [v, d2]=DFS(u, -1, tree, dist2, visited);

    if (d2>bestLen) {
      bestLen=d2;
      bestU=u;
      bestV=v;
    }
  }

  if (bestLen==0) std::cout << "-1";
  else std::cout << bestU+1 << ' ' << bestV+1;
  return 0;
}


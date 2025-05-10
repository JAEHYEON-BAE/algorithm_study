// 5971

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

void dfs(int node, int parent, const std::vector<std::unordered_set<int>> &tree, int d, std::vector<int> &depth)
{
  depth[node]=d;
  for (const int &next:tree[node]) {
    if (next!=parent) dfs(next, node, tree, d+1, depth); 
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> parent(n);
  std::vector<std::unordered_set<int>> tree(n);
  parent[0]=-1;
  for (int i=1;i<n;++i) {
    std::cin >> parent[i];
    --parent[i];
    tree[parent[i]].insert(i);
  }

  std::vector<int> depth(n);
  dfs(0, -1, tree, 0, depth);
  
  int u, v;
  while (m--) {
    std::cin >> u >> v;
    --u;--v;

    if (depth[u]<depth[v]) std::swap(u, v);
    while (depth[u]>depth[v]) u=parent[u];

    while (u!=v) {
      u=parent[u];
      v=parent[v];
    }
    std::cout << u+1 << '\n';
  }
  return 0;
}
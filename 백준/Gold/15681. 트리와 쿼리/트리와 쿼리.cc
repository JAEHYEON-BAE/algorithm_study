// 15681

#include <iostream>
#include <vector>
#include <set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void search(int curr, int prev, const std::vector<std::set<int>>&tree, std::vector<int>&childs)
{
  for (int next: tree[curr]) {
    if (next==prev) continue;
    search(next, curr, tree, childs);
    childs[curr]+=childs[next];
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, r, q;  std::cin >> n >> r >> q;
  int u, v;
  std::vector<std::set<int>> tree(n+1);
  for (int i=0;i<n-1;++i) {
    std::cin >> u >> v;
    tree[u].insert(v);
    tree[v].insert(u);
  }
  std::vector<int> childs(n+1, 1);
  // childs[r]=n;
  search(r, 0, tree, childs);
  while (q--) {
    std::cin >> u;
    std::cout << childs[u] << '\n';
  }

  return 0; 
}

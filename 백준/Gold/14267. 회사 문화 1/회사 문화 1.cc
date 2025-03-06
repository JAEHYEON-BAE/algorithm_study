// 14267

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

void DFS(int node, int tmp, std::vector<int> &v, const std::vector<std::vector<int>> &tree)
{
  v[node]+=tmp;
  for (int next:tree[node]) {
    DFS(next, v[node], v, tree);
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> tree(n);
  int x;
  for (int i=0;i<n;++i) {
    std::cin >> x;
    if (x<=0) continue;
    tree[x-1].push_back(i);
  }
  int i, w;
  std::vector<int> v(n, 0);
  while (m--) {
    std::cin >> i >> w;
    v[i-1]+=w;
  }
  DFS(0, 0, v, tree);
  for (int x:v) std::cout << x << ' ';
  return 0;
}
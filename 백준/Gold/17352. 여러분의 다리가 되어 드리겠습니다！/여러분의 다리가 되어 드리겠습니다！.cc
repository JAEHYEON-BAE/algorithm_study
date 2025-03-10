// 17352

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int find(int x, std::vector<int> &root)
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}

void unite(int x, int y, std::vector<int> &root, std::vector<int> &rank)
{
  int root_x=find(x, root), root_y=find(y, root);
  if (root_x==root_y) return;
  if (rank[root_x]<rank[root_y]) {
    root[root_x]=root_y;
  }
  else if (rank[root_x]>rank[root_y]) {
    root[root_y]=root_x;
  }
  else {
    root[root_x]=root_y;
    ++rank[root_y];
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> root(n), rank(n, 0);
  for (int i=0;i<n;++i) root[i]=i;
  
  int u, v;
  for (int i=0;i<n-2;++i) {
    std::cin >> u >> v;
    unite(--u, --v, root, rank);
  }

  for (int i=1;i<n;++i) {
    if (find(i, root)!=find(0, root)) {
      std::cout << "1 " << i+1;
      return 0;
    }
  }
  

  return 0;
}
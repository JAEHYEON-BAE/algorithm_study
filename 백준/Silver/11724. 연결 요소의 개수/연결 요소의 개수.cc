// 11726

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

class DSU
{
  int n;
  std::vector<int> root, rank;


public:
  DSU(int n): n(n), root(n), rank(n, 0) {
    for (int i=0;i<n;++i) root[i]=i;
  }

  int find(int x) {
    if (x==root[x]) return x;
    return root[x]=find(root[x]);
  }
  void unite(int x, int y) {
    x=find(x), y=find(y);
    if (x==y) return;

    if (rank[x]>rank[y]) root[y]=x;
    else if (rank[x]<rank[y]) root[x]=y;
    else {
      root[x]=y;
      ++rank[y];
    }
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  DSU dsu(n);
  for (int i=0;i<m;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;
    dsu.unite(u, v);
  }

  std::set<int> s;
  for (int i=0;i<n;++i) s.insert(dsu.find(i));
  std::cout << s.size();
  return 0;
}
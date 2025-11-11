// 4792

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct Edge
{
  int to;
  char c;
  Edge() {}
  Edge(int t, char c): to(t), c(c) {}
};

struct DSJ
{
  int n;
  std::vector<int> root, rank;

  DSJ(int n): n(n), root(n), rank(n) {
    for (int i=0;i<n;++i) root[i]=i, rank[i]=0;
  }

  int find(int x) {
    if (x==root[x]) return x;
    return root[x]=find(root[x]);
  }

  bool unite(int x, int y) {
    x=find(x), y=find(y);
    if (x==y) return 0;
    if (rank[x]<rank[y]) root[x]=y;
    else {
      root[y]=x;
      if (rank[x]==rank[y]) ++rank[x];
    }
    return 1;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  
  while (std::cin >> n >> m >> k) {
    if (!n&&!m&&!k) break;

    std::vector<std::vector<std::pair<int, int>>> edges(2);
    for (int i=0;i<m;++i) {
      char c; int f, t;
      std::cin >> c >> f >> t;
      --f;--t;
      if (c=='R') edges[0].push_back({f, t});
      else if (c=='B') edges[1].push_back({f, t});
      else assert(!"INVALID INPUT");
    }
    int min=0;
    DSJ d1(n);
    for (const auto &p:edges[0]) d1.unite(p.first, p.second);
    for (const auto &p:edges[1]) if (d1.unite(p.first, p.second)) ++min;

    int max=0;
    DSJ d2(n);
    for (const auto &p:edges[1]) if (d2.unite(p.first, p.second)) ++max;

    std::cout << (min<=k && k<=max) << '\n';
    
  }
  
  return 0;
}
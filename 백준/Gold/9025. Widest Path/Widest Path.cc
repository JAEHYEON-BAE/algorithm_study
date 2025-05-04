// 9025

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;

struct Edge
{
  int u, v, b;
  Edge(int u, int v, int b): u(u), v(v), b(b) {}
  bool operator<(const Edge &other) const {
    return b>other.b;
  }
};

int find(int x, std::vector<int> &root)
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}

void unite(int x, int y, std::vector<int> &root, std::vector<int> &rank)
{
  int root_x=find(x, root);
  int root_y=find(y, root);

  if (root_x==root_y) return;

  if (rank[root_x]<rank[root_y]) root[root_x]=root_y;
  else if (rank[root_x]>rank[root_y]) root[root_y]=root_x;
  else {
    root[root_x]=root_y;
    ++rank[root_y];
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int bandwidth=INF;
    
    int n, m, s, t;  std::cin >> n >> m >> s >> t;
    --s,--t;
    std::vector<Edge> edges;
    for (int i=0;i<m;++i) {
      int u, v, b;  std::cin >> u >> v >> b;
      --u,--v;
      edges.push_back(Edge(u, v, b));
    }
    std::sort(edges.begin(), edges.end());

    std::vector<int> root(n), rank(n, 0);
    for (int i=0;i<n;++i) root[i]=i;

    int idx=0;
    while (find(s, root)!=find(t, root)) {
      assert(idx<m);
      unite(edges[idx].u, edges[idx].v, root, rank);
      bandwidth=std::min(bandwidth, edges[idx].b);
      ++idx;
    }
    std::cout << bandwidth << '\n';
  }
  return 0;
}
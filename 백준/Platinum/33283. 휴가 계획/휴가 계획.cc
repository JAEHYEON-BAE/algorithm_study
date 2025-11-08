// 33283

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct DSU
{
  int n;
  std::vector<int> root, rank;

  DSU(int n): n(n) {
    root.resize(n);
    rank.assign(n, 0);
    for (int i=0;i<n;++i) root[i]=i;
  }

  int find(int x) {
    if (x==root[x]) return x;
    return root[x]=find(root[x]);
  }

  bool unite(int x, int y) {
    int rx=find(x), ry=find(y);
    if (rx==ry) return 0;
    if (rank[rx]>rank[ry]) root[ry]=rx;
    else {
      root[rx]=ry;
      if (rank[rx]==rank[ry]) ++rank[ry];
    }
    return 1;
  }
};

struct LCA
{
  int n;
  const std::vector<std::vector<int>> &G;
  std::vector<int> depth;
  std::vector<std::vector<int>> parent;
  int LOG;

  LCA(int n, const std::vector<std::vector<int>> &G): n(n), G(G) {
    depth.resize(n);
    depth[0]=0;
    LOG=0;
    while ((1<<LOG)<=n) ++LOG;
    parent.assign(n, std::vector<int>(LOG, -1));

    DFS(0, -1);
    build_table();
  }

  void DFS(int u, int p) {
    parent[u][0]=p;
    for (const int &v:G[u]) if (v!=p) {
      depth[v]=1+depth[u];
      DFS(v, u);
    }
  }

  void build_table() {
    for (int k=1;k<LOG;++k) for (int i=0;i<n;++i) if (parent[i][k-1]!=-1) {
      parent[i][k]=parent[ parent[i][k-1] ][k-1];
    }
  }

  int lca(int u, int v) {
    if (depth[u]<depth[v]) std::swap(u, v);
    if (depth[u]!=depth[v]) {
      int diff=depth[u]-depth[v];
      for (int i=0;diff;++i, diff>>=1) if (diff&1) {
        u=parent[u][i];
      }
    }
    assert(depth[u]==depth[v]);
    if (u==v) return u;

    for (int i=LOG-1;i>=0;--i) if (parent[u][i]!=parent[v][i]) {
      u=parent[u][i];
      v=parent[v][i];
    }
    u=parent[u][0];
    v=parent[v][0];
    assert(u==v);
    return u;
  }

  int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[lca(u, v)];
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  DSU dsu(n);
  std::vector<std::vector<int>> G(n);
  for (int i=0;i<m;++i) {
    int u, v;  std::cin >> u >> v;
    --u, --v;
    if (dsu.unite(u, v)) {
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  
  LCA lca(n, G);
  
  int q;  std::cin >> q;
  while (q--) {
    int s, e;  std::cin >> s >> e;
    --s, --e;
    std::cout << lca.dist(s, e)-1 << '\n';
  }
  return 0;
}
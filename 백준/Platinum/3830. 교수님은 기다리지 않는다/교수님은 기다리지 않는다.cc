// 3830

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>


class _3830
{
  const int &n;
  std::vector<int> root, rank;
  std::vector<int> weight;

  int find(int x) {
    if (x==root[x]) return x;
    int r=find(root[x]);
    weight[x]+=weight[root[x]];
    return root[x]=r;
  }
  void unite(int x, int y, int w) {
    int root_x=find(x);
    int root_y=find(y);
    if (root_x==root_y) return;
    if (rank[root_x]<rank[root_y]) {
      root[root_x]=root_y;
      weight[root_x]=weight[root_y]-weight[x]+weight[y]-w;
    }
    else {
      root[root_y]=root_x;
      weight[root_y]=weight[root_x]+weight[x]+w-weight[y];
      if (rank[root_x]==rank[root_y]) ++rank[root_x];
    }
    return;
  }

public:
  _3830(const int &n): n(n) {
    root.resize(n);
    for (int i=0;i<n;++i) root[i]=i;
    rank.assign(n, 0);
    weight.assign(n, 0);
  }
  void measure(int a, int b, int w) {
    unite(a, b, w);
  }
  void query(int a, int b) {
    if (find(a)!=find(b)) std::cout << "UNKNOWN\n";
    else {
      std::cout << weight[b]-weight[a] << '\n';
    }
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;
  while (std::cin >> n >> m) {
    if (!n && !m) break;

    _3830 x(n);
    for (int i=0;i<m;++i) {
      char c; std::cin >> c;
      if (c=='!'){
        int a, b, w;  std::cin >> a >> b >> w;
        --a;--b;
        x.measure(a, b, w);
      }
      else if (c=='?') {
        int a, b;  std::cin >> a >> b;
        --a;--b;
        x.query(a, b);
      }
    }
  }

  return 0;
}
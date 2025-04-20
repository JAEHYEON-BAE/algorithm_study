// 15835

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

struct Edge
{
  int u, v, w;
  Edge(int u, int v, int w): u(u), v(v), w(w) {}
  bool operator<(const Edge &other) const {
    return w>other.w;
  }
};

int find(int x, std::vector<int> &root)
{
  if (root[x]==x) return x;
  return root[x]=find(root[x], root);
}

bool unite(int x, int y, std::vector<int> &root, std::vector<int> &rank)
{
  int _x=find(x, root);
  int _y=find(y, root);
  if (_x==_y) return 0;
  if (rank[_x]<rank[_y]) root[_x]=_y;
  else if (rank[_x]>rank[_y]) root[_y]=_x;
  else {
    root[_x]=_y;
    ++rank[_y];
  }
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int _case=1;_case<=t;++_case) {
    int n, m;  std::cin >> n >> m;
    std::priority_queue<Edge> pq;
    
    for (int i=0;i<m;++i) {
      int u, v, w;  std::cin >> u >> v >> w;
      --u;--v;
      pq.push(Edge(u, v, w));
    }
    
    std::vector<int> root(n), rank(n, 0);
    for (int i=0;i<n;++i) root[i]=i;

    int dist=0;
    while (!pq.empty()) {
      Edge edge=pq.top();
      pq.pop();
      if (unite(edge.u, edge.v, root, rank)) {
        dist+=edge.w;
      }
    }

    std::cout << "Case #" << _case << ": " << dist << " meters\n";
  }

  return 0;
}
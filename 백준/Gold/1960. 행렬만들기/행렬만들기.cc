// 1960

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

constexpr int INF=(~0u)>>1;

struct Edge
{
  int to, rev, cap;
  Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
};

class Dinic
{
  int n;
  std::vector<int> depth;
  std::vector<int> it;

  bool BFS(int s, int t) {
    std::fill(depth.begin(), depth.end(), -1);
    std::queue<int> q;
    
    q.push(s);
    depth[s]=0;

    while (!q.empty()) {
      int u=q.front();  q.pop();
      for (const Edge &e:graph[u]) if (e.cap && depth[e.to]==-1) {
        depth[e.to]=1+depth[u];
        q.push(e.to);
      }
    }
    return depth[t]>=0;
  }

  int DFS(int s, int t, int flow) {
    if (s==t) return flow;
    for (int &i=it[s];i<graph[s].size();++i) {
      Edge &e=graph[s][i];
      if (!e.cap || depth[e.to]!=1+depth[s]) continue;
      int pushed=DFS(e.to, t, std::min(flow, e.cap));
      if (pushed) {
        e.cap-=pushed;
        graph[e.to][e.rev].cap+=pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  std::vector<std::vector<Edge>> graph;

  Dinic(int n) {
    graph.resize(n);
    depth.assign(n, -1);
    it.assign(n, 0);
  }

  void add_edge(int u, int v, int c) {
    Edge a(v, graph[v].size(), c);
    Edge b(u, graph[u].size(), 0);

    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  int max_flow(int s, int t) {
    int flow=0;
    while (BFS(s, t)) {
      std::fill(it.begin(), it.end(), 0);
      while (1) {
        int pushed=DFS(s, t, INF);
        if (!pushed) break;
        flow+=pushed;
      }
    }
    return flow;
  }
};


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> r(n), c(n);
  int sum_r=0, sum_c=0;
  for (int &x:r) std::cin >> x, sum_r+=x;
  for (int &x:c) std::cin >> x, sum_c+=x;

  if (sum_r!=sum_c) {
    std::cout << "-1";
    return 0;
  }
  // source=0, row=1~n, col=n+1~2n, sink=2n+1
  int s=0, t=1|n<<1;

  Dinic dinic((n+1)<<1);
  for (int i=0;i<n;++i) {
    if (r[i]) dinic.add_edge(0, i+1, r[i]);
    if (c[i]) dinic.add_edge(n+i+1, t, c[i]);
  }
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    dinic.add_edge(i+1, n+j+1, 1);
  }

  int max_flow=dinic.max_flow(s, t);
  if (max_flow!=sum_r) {
    std::cout << "-1";
    return 0;
  }

  std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));

  for (int i=0;i<n;++i) {
    for (const Edge &e:dinic.graph[i+1]) {
      if (e.to>n && e.to<=n<<1 && e.cap==0) {
        ans[i][e.to-n-1]=1;
      } 
    }
  }
  std::cout << "1\n";
  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) std::cout << ans[i][j];
    std::cout << '\n';
  }
  return 0;
}
// 2316

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

struct Edge
{
  int to, rev;
  bool cap;
  Edge(){}
  Edge(int to, int rev, bool cap): to(to), rev(rev), cap(cap){}
};

class Dinic
{
  int n;  
  std::vector<std::vector<Edge>> &graph;
  std::vector<int> level, iter;

  /* BFS: building LEVEL graph */
  void BFS(int s) {
    level.assign(n, -1);
    std::queue<int> q;
    level[s]=0;
    q.push(s);
    while (!q.empty()) {
      int v=q.front();  q.pop();
      for (const Edge &e:graph[v]) {
        if (e.cap && level[e.to]==-1) {
          level[e.to]=level[v]+1;
          q.push(e.to);
        }
      }
    }
    return;
  }
  /* DFS: searching augmenting path */
  bool DFS(int v, int t) {
    if (v==t) return 1;
    for (int &it=iter[v];it<graph[v].size();++it) {
      Edge &e=graph[v][it];
      if (e.cap && level[v]<level[e.to] && DFS(e.to, t)) {
        e.cap=0;
        graph[e.to][e.rev].cap=1;
        return 1;
      }
    }
    return 0;
  }

public:
  Dinic(int n, std::vector<std::vector<Edge>> &graph): n(n), graph(graph) {}

  int max_flow(int s, int t) {
    int flow=0;
    while (1) {
      BFS(s);
      if (level[t]==-1) break;
      iter.assign(n, 0);
      while (DFS(s, t)) ++flow;
    }
    return flow;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, p;  std::cin >> n >> p;
  std::vector<std::vector<Edge>> graph(n<<1);
  for (int i=2;i<n;++i) {
    graph[i<<1].push_back(Edge(1|i<<1, graph[1|i<<1].size(), 1));
    graph[1|i<<1].push_back(Edge(i<<1, graph[i<<1].size()-1, 0));
  }
  for (int i=0;i<p;++i) {
    int u, v;  std::cin >> u >> v;
    --u;--v;

    int u_out=(u!=0)?(1|u<<1):u;
    int v_in=(v!=1)?v<<1:v;
    int v_out=(v!=0)?(1|v<<1):v;
    int u_in=(u!=1)?u<<1:u;
    graph[u_out].push_back(Edge(v_in, graph[v_in].size(), 1));
    graph[v_in].push_back(Edge(u_out, graph[u_out].size()-1, 0));
    graph[v_out].push_back(Edge(u_in, graph[u_in].size(), 1));
    graph[u_in].push_back(Edge(v_out, graph[v_out].size()-1, 0));
  }

  Dinic x(n<<1, graph);
  std::cout << x.max_flow(0, 1);
  return 0;
}
// 6086

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
  std::vector<std::vector<Edge>> graph;
  std::vector<int> depth;
  std::vector<int> it;

  bool BFS(int s, int t) {
    std::fill(depth.begin(), depth.end(), -1);
    std::queue<int> q;

    depth[s]=0;
    q.push(s);
    while (!q.empty()) {
      int curr=q.front();  q.pop();
      for (const Edge &edge:graph[curr]) {
        int next=edge.to;
        if (edge.cap>0 && depth[next]==-1) {
          depth[next]=1+depth[curr];
          q.push(next);
        }
      }
    }
    return depth[t]>=0;
  }

  int DFS(int s, int t, int flow) {
    if (s==t) return flow;
    for (int &i=it[s];i<graph[s].size();++i) {
      Edge &e=graph[s][i];
      if (e.cap<=0 || depth[e.to]!=1+depth[s]) continue;
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
  Dinic() {
    graph.resize(52);
    depth.assign(52, -1);
    it.assign(52, 0);
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
        if (pushed==0) break;
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
  Dinic dinic;
  for (int i=0;i<n;++i) {
    char cu, cv;  int x;
    std::cin >> cu >> cv >> x;
    int u, v;
    if (isupper(cu)) u=cu-'A';
    else u=cu-'a'+26;
    
    if (isupper(cv)) v=cv-'A';
    else v=cv-'a'+26;

    dinic.add_edge(u, v, x);
    dinic.add_edge(v, u, x);
  }
  std::cout << dinic.max_flow(0, 25);
  
  return 0;
}
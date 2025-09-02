// 13907

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

constexpr int INF=(~0u)>>1;

struct Edge
{
  int to, cost;
  Edge() {}
  Edge(int t, int c): to(t), cost(c) {}
};

struct Node
{
  int id, cost, length;
  Node() {}
  Node(int i, int c, int l): id(i), cost(c), length(l) {}

  bool operator<(const Node &o) const {
    return cost>o.cost;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  int s, d;  std::cin >> s >> d;
  --s,--d;

  std::vector<std::vector<Edge>> graph(n);
  for (int i=0;i<m;++i) {
    int a, b, w;  std::cin >> a >> b >> w;
    --a,--b;

    graph[a].push_back(Edge(b, w));
    graph[b].push_back(Edge(a, w));
  }


  // dist[node][edge_cnt] := 간선을 여러 개 지날 때, 가중치 합의 최솟값
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));

  // 변형 dijkstra
  std::priority_queue<Node> pq;

  dist[s][0]=0;
  pq.push(Node(s, 0, 0));
  while (!pq.empty()) {
    auto [curr, cost, length]=pq.top();
    pq.pop();

    if (length>=n || dist[curr][length]<cost) continue;

    for (const Edge &e:graph[curr]) {
      int next=e.to;
      int cost_n=cost+e.cost;
      int length_n=length+1;
      if (length_n>=n) continue;
      if (dist[next][length_n]>cost_n) {
        dist[next][length_n]=cost_n;
        pq.push(Node(next, cost_n, length_n));
      }
    }
  }

  std::vector<int> res=dist[d];
  
  // for (int &x:res) std::cout << x << ' ' ;
  // std::cout << std::endl;
  
  std::cout << *std::min_element(res.begin(), res.end()) << '\n';

  while (k--) {
    int x;  std::cin >> x;
    int min=INF;
    for (int i=0;i<n;++i) {
      if (res[i]!=INF) res[i]+=i*x;
      min=std::min(min, res[i]);
    }
    std::cout << min << '\n';
  }
  std::cout.flush();
  return 0;
}
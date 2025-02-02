// 11779

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  int u, v, w;  
  std::vector<std::unordered_map<int, int>> graph(n+1);
  for (int i=0;i<m;++i) {
    std::cin >> u >> v >> w;
    if (graph[u].find(v)==graph[u].end()) graph[u][v]=w;
    else graph[u][v]=std::min(graph[u][v], w);
  }
  int s, e;  std::cin >> s >> e;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  pq.push({0, s});
  std::vector<int> dist(n+1, INF);
  dist[s]=0;
  std::vector<bool> done(n+1, false);

  std::vector<int> parent(n+1, -1);

  while (!pq.empty()) {
    int curr_node=pq.top().second;
    int curr_dist=pq.top().first;
    pq.pop();
    if (done[curr_node]) continue;
    done[curr_node]=true;
    if (curr_dist>dist[curr_node]) continue;

    for (const auto &next: graph[curr_node]) {
      int next_node=next.first;
      int weight=next.second;

      if (dist[next_node]>dist[curr_node]+weight) {
        dist[next_node]=dist[curr_node]+weight;
        parent[next_node]=curr_node;
        pq.push({dist[next_node], next_node});
      }
    }
  }
  std::vector<int> path;
  for (int i=e;i!=s;i=parent[i]) path.push_back(i);
  path.push_back(s);
  std::cout << dist[e] << '\n' << path.size() << '\n';
  for (auto i=path.end()-1;i>=path.begin();--i) std::cout << *i << ' ';
  
  return 0; 
}

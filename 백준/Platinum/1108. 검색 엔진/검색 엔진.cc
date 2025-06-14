// 1108

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int Tarjans(int node, const std::unordered_map<int, std::unordered_set<int>> &map, std::unordered_map<int, int> &SCC, std::vector<bool> &done, std::vector<int> &d)
{
  static std::stack<int> stk;
  static int scc_id=0;
  static int num=0;

  d[node]=++num;
  stk.push(node);

  int parent=d[node];
  for (const int &next:map.at(node)) {
    if (!d[next]) parent=std::min(parent, Tarjans(next, map, SCC, done, d));
    else if (!done[next]) parent=std::min(parent, d[next]);
  }

  if (parent==d[node]) {
    while (!stk.empty()) {
      int top=stk.top();
      stk.pop();
      SCC[top]=scc_id;
      done[top]=1;
      
      if (top==node) break;
    }
    ++scc_id;
  }
  return parent;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  /** 1108
    * 1) hashing: site name -> site ID
    * 2) build the graph
    * 3) extract SCC ID for each node via DFS (Tarjan's Algorithm)
    * 4) remove edges between the SCC group
    * 5) update the score of each node via topological ordering
    */
  
  int n;  std::cin >> n;
  std::unordered_map<std::string, int> ID;
  std::unordered_map<int, std::unordered_set<int>> map;

  /* Hashing & Graph Building */
  int id=1;
  for (int i=0;i<n;++i) {
    std::string s; int cnt;
    std::cin >> s >> cnt;
    if (ID.find(s)==ID.end()) ID[s]=id++;
    if (map.find(ID[s])==map.end()) map[ID[s]]={};
    while (cnt--) {
      std::string ss;  std::cin >> ss;
      if (ID.find(ss)==ID.end()) ID[ss]=id++;
      map[ID[ss]].insert(ID[s]);
    }
  }


  /* extract the SCC ID for each node */
  std::unordered_map<int, int> SCC;
  std::vector<bool> done(id, 0);
  std::vector<int> d(id, 0);
  for (int i=1;i<id;++i) if (!d[i]) {
    Tarjans(i, map, SCC, done, d);
  }

  
  /* re-build the DAG graph with no SCC */
  std::vector<std::unordered_set<int>> new_graph(id);
  std::vector<int> in_degree(id);
  for (int u=1;u<id;++u) for (const int &v:map.at(u)) {
    if (SCC[u]!=SCC[v]) {
      new_graph[u].insert(v);
      ++in_degree[v];
    }
  }


  /* topological ordering */
  std::queue<int> q;
  for (int i=1;i<id;++i) if (in_degree[i]==0) {
    q.push(i);
  }

  std::vector<long long int> score(id, 1LL);
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    for (const int &next:new_graph[curr]) {
      assert(SCC[next]!=SCC[curr]);
      
      score[next]+=score[curr];
      if (--in_degree[next]==0) q.push(next);
    }
  }
  
  std::string target;  std::cin >> target; 
  std::cout << score[ID.at(target)];

  return 0;
}

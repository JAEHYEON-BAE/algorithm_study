// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <stack>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int Tarjans(int node, const std::vector<std::vector<int>> &graph, std::vector<int> &d, std::vector<int> &SCC_id, int &scc_n, std::stack<int> &stk, int &id, std::vector<bool> &done)
{

  d[node]=++id;
  stk.push(node);

  int low_link=d[node];
  for (const int &next:graph.at(node)) {
    if (!d[next]) low_link=std::min(low_link, Tarjans(next, graph, d, SCC_id, scc_n, stk, id, done));
    else if (!done[next]) low_link=std::min(low_link, d[next]);
  }

  if (low_link==d[node]) {
    
    while (!stk.empty()) {
      int top=stk.top();
      stk.pop();
      SCC_id[top]=scc_n;
      done[top]=1;

      if (top==node) break;
    }

    ++scc_n;
  }
  return low_link;
}



int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, m;  std::cin >> n >> m;
    if (m==0) {std::cout << n << '\n'; continue;}

    std::vector<std::vector<int>> graph(n);
    for (int i=0;i<m;++i) {
      int a, b;  std::cin >> a >> b;
      --a;--b;
      graph[a].push_back(b);
    }
    std::vector<int> SCC_id(n, -1);
    std::vector<int> d(n, 0);
    int scc_n=0;
    std::stack<int> stack;
    int id=0;
    std::vector<bool> done(n, false);
    for (int i=0;i<n;++i) if (!d[i]) {
      Tarjans(i, graph, d, SCC_id, scc_n, stack, id, done);
    }

    if (scc_n==1) {std::cout << "0\n"; continue;}

    std::vector<int> in_degree(scc_n, 0), out_degree(scc_n, 0);
    
    for (int u=0;u<n;++u) for (const int &v:graph.at(u)) {
      if (SCC_id[u]==SCC_id[v]) continue;
      ++in_degree[SCC_id[v]];
      ++out_degree[SCC_id[u]];
    }

    int sink=0, source=0;
    for (int i=0;i<scc_n;++i) {
      if (in_degree[i]==0) ++source;
      if (out_degree[i]==0) ++sink;
    }

    std::cout << std::max(source, sink) << '\n';
  }
 
  return 0;
}

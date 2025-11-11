// 6543

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct SCC
{
  int n;  
  const std::vector<std::vector<int>> &G;
  std::vector<int> index, done, scc;
  int id=0, scc_id=0;
  std::vector<int> stk;
  std::vector<std::vector<int>> scc_group;

public:
  SCC(int n, const std::vector<std::vector<int>> &G): n(n), G(G) {
    index.assign(n, -1);
    done.assign(n, 0);
    scc.assign(n, -1);

    for (int i=0;i<n;++i) if (index[i]==-1) DFS(i);
  }

private:
  int DFS(int u) {
    index[u]=id++;
    int lowlink=index[u];
    stk.push_back(u);
    for (const int &v:G[u]) {
      if (index[v]==-1) lowlink=std::min(lowlink, DFS(v));
      else if (!done[v]) lowlink=std::min(lowlink, index[v]);
    }

    if (lowlink==index[u]) {
      std::vector<int> group;
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        scc[top]=scc_id;
        group.push_back(top);
        done[top]=1;
        if (top==u) break;
      }
      scc_group.push_back(group);
      ++scc_id;
    }
    return lowlink;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m; 
  while (std::cin >> n) {
    if (!n) break;
    std::cin >> m;
    std::vector<std::vector<int>> G(n);
    for (int i=0;i<m;++i) {
      int v, w;  std::cin >> v >> w;
      --v, --w;
      G[v].push_back(w);
    }
    SCC x(n, G);
    std::vector<int> out_degree(x.scc_id, 0);
    for (int u=0;u<n;++u) for (const int &v:G[u]) {
      int a=x.scc[u];
      int b=x.scc[v];
      if (a!=b) ++out_degree[a];
    }

    std::vector<int> ans;
    for (int i=0;i<x.scc_id;++i) if (out_degree[i]==0) {
      for (const int &u:x.scc_group[i]) ans.push_back(u);
    }

    std::sort(ans.begin(), ans.end());
    for (const int &u:ans) std::cout << u+1 << ' ';
    std::cout << '\n';
  }
  
  return 0;
}
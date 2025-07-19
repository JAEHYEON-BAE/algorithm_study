// 3648

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

class TarjanSCC
{
  const int &n;
  int size;
  const std::vector<std::vector<int>> &graph;
  std::vector<int> dfs_num;
  std::vector<bool> done;
  int id=0;
  int scc_id=0;
  std::vector<int> scc;
  std::vector<int> stk;

  int DFS(int u) {
    dfs_num[u]=id++;
    stk.push_back(u);

    int lowlink=dfs_num[u];
    for (const int &v:graph.at(u)) {
      if (dfs_num[v]==-1) {
        lowlink=std::min(lowlink, DFS(v));
      }
      else if (!done[v]) {
        lowlink=std::min(lowlink, dfs_num[v]);
      }
    }

    if (lowlink==dfs_num[u]) {
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        done[top]=1;
        scc[top]=scc_id;
        if (top==u) break;
      }
      ++scc_id;
    }
    return lowlink;
  }
  bool valid() {
    for (int i=1;i<=n;++i) if (scc[i]==scc[i+n]) return 0;
    return 1;
  }

public:
  TarjanSCC(const int &n, const std::vector<std::vector<int>> &graph): n(n), graph(graph) {
    size=1|(n<<1);
    dfs_num.assign(size, -1);
    done.assign(size, 0);
    scc.assign(size, -1);
  }

  bool solve() {
    for (int i=1;i<size;++i) if (dfs_num[i]==-1) DFS(i);
    return valid();
  }

};
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> graph(1|(n<<1));

    std::unordered_map<int, int> idx;
    for (int i=1;i<=n;++i) {
      idx[-i]=n+i;
      idx[i]=i;
    }

    graph[idx[-1]].push_back(1);
    for (int i=0;i<m;++i) {
      int a, b;  std::cin >> a >> b;
      graph[idx[-a]].push_back(idx[b]);
      graph[idx[-b]].push_back(idx[a]);
    }

    TarjanSCC x(n, graph);
    std::cout << (x.solve()?"yes\n":"no\n");
  }

  return 0;
}
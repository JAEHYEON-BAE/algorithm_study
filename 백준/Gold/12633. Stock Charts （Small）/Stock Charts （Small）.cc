// 12633

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

inline bool below(const std::vector<int> &a, const std::vector<int> &b)
{
  assert(a.size()==b.size());
  int n=a.size();
  for (int i=0;i<n;++i) if (a[i]>=b[i]) return 0;
  return 1;
}

class BP_M
{
  const int &n;
  const std::vector<std::vector<int>> &graph;
  std::vector<int> match;
  std::vector<bool> done;

  bool DFS(int u) {
    for (const int &v:graph[u]) {
      if (done[v]) continue;
      done[v]=1;
      if (match[v]==-1 || DFS(match[v])) {
        match[v]=u;
        return 1;
      }
    }
    return 0;
  }

public:
  BP_M(const int &n, const std::vector<std::vector<int>> &graph): n(n), graph(graph) {
    match.assign(n, -1);
    done.assign(n, 0);
  }

  int max_matching() {
    int res=0;
    for (int i=0;i<n;++i) {
      done.assign(n, 0);
      if (DFS(i)) ++res;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int T;  std::cin >> T;
  for (int t=1;t<=T;++t) {
    int n, k;  std::cin >> n >> k;
    std::vector<std::vector<int>> p(n, std::vector<int>(k));
    for (auto &r:p) for (int &v:r) std::cin >> v;

    std::vector<std::vector<int>> graph(n);
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
      if (i!=j && below(p[i], p[j])) {
        graph[i].push_back(j);
      }
    }

    BP_M x(n, graph);
    std::cout << "Case #" << t << ": " << n-x.max_matching() << '\n';
  }

  return 0;
}

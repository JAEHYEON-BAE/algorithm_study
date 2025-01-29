// 8462

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

struct Viewer
{
  std::string up, down;
};

bool bp_m(int node, const std::vector<std::vector<int>> &graph, std::vector<int> &match, std::vector<bool> &done) 
{
  for (const int& neighbor: graph[node]) {
    if (!done[neighbor]) {
      done[neighbor]=true;
      if (match[neighbor]==-1 || bp_m(match[neighbor], graph, match, done)) {
        match[neighbor] = node;
        return true;
      }
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  std::cin >> tc;
  int c, d, v;
  while (tc--) {
    std::cin >> c >> d >> v;
    std::string up,down;
    std::vector<Viewer> viewers(v);
    std::vector<std::vector<int>> graph(v);
    for (int i=0;i<v;++i) {
      std::cin >> viewers[i].up >> viewers[i].down;
      for (int j=0;j<i;++j) {
        if (viewers[i].up==viewers[j].down || viewers[i].down==viewers[j].up) {
          graph[i].push_back(j), graph[j].push_back(i);
        }
      }
    }

    int cnt=0;
    std::vector<int> match(v, -1);
    for (int i=0;i<v;++i) {
      std::vector<bool> done(v, false);
      if (bp_m(i, graph, match, done)) ++cnt;      
    }
    std::cout << v-cnt/2 << '\n';
  }

  return 0; 
}

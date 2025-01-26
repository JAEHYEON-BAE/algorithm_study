// 11377

#include <iostream>
#include <vector>
#include <algorithm>

bool bp_m(int node, const std::vector<std::vector<int>> &graph, std::vector<int> &match, std::vector<bool>& done)
{
  for (int next: graph[node]) {
    if (!done[next]) {
      done[next] = true;
      if (match[next]==-1 || bp_m(match[next], graph, match, done)) {
        match[next]=node;
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

  int n, m, k;  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> graph(n);
  for (int i=0;i<n;++i) {
    int c;  std::cin >> c;
    graph[i].resize(c);
    for (int j=0;j<c;++j) {
      std::cin >> graph[i][j];
      --graph[i][j];
    }
  }

  int cnt=0;
  
  std::vector<int> match(m, -1);
  std::vector<bool> done(m, false);
  for (int i=0;i<n;++i) {
    std::fill(done.begin(), done.end(), false);
    if (bp_m(i, graph, match, done)) {
      ++cnt;
    }    
  }
  if (cnt==m) {std::cout << cnt; return 0;}
  for (int i=0;i<n;++i) {
    std::fill(done.begin(), done.end(), false);
    if (bp_m(i, graph, match, done)) {
      if (++cnt==m || --k==0) {std::cout << cnt; return 0;}
    }
  }
  std::cout << cnt;  
  return 0; 
}

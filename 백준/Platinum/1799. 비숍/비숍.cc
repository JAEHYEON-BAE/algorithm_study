// 1799

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>

bool bp_m(int x, std::vector<int> &match, std::vector<bool> &done, const std::vector<std::unordered_set<int>> &graph)
{
  for (const int &y:graph[x]) if (!done[y]) {
    done[y]=1;
    if (match[y]==-1 || bp_m(match[y], match, done, graph)) {
      match[y]=x;
      return 1;
    }
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::unordered_set<int>> graph((n<<1)-1);
  
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    int x;  std::cin >> x;
    if (x) graph[i+j].insert(i-j+n-1);
  }
  std::vector<int> match((n<<1)-1, -1);
  int cnt=0;
  for (int i=0;i<(n<<1)-1;++i) {
    std::vector<bool> done((n<<1)-1, 0);
    if (bp_m(i, match, done, graph)) ++cnt;
  }
  std::cout << cnt;
  return 0;
}
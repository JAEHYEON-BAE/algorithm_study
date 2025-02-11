// 1937

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
std::vector<int> dp;
std::vector<std::vector<int>> graph;

int solve(int node) {
  if (dp[node]!=-1) return dp[node];
  int tmp=0;
  for (int neighbor: graph[node]) {
    tmp=std::max(tmp, solve(neighbor));
  }
  return dp[node]=1+tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> map(n, std::vector<int>(n));
  graph.resize(n*n);
  
  for (int i=0;i<n*n;++i) {
    int r=i/n, c=i%n;
    std::cin >> map[r][c];
    if (r>0) {
      if (map[r-1][c]<map[r][c]) graph[i-n].push_back(i);
      else if (map[r-1][c]>map[r][c]) graph[i].push_back(i-n);
    }
    if (c>0) {
      if (map[r][c-1]<map[r][c]) graph[i-1].push_back(i);
      else if (map[r][c-1]>map[r][c]) graph[i].push_back(i-1);
    }
  }

  dp.assign(n*n, -1);
  int result=-1;
  for (int i=0;i<n*n;++i) {
    if (dp[i]!=-1) result=std::max(result, dp[i]);
    else result=std::max(result, solve(i));
  }
  std::cout << result;

  return 0; 
}
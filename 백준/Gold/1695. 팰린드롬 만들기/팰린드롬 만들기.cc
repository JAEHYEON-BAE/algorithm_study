// 1695

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
std::vector<std::vector<int>> dp;

int solve(int s, int e, const std::vector<int> &v) {
  if (s>=e) return 0;
  if (dp[s][e]!=-1) return dp[s][e];
  int cnt=0;
  if (v[s]==v[e]) cnt=solve(s+1, e-1, v);
  else cnt=std::min(solve(s, e-1, v)+1, solve(s+1, e, v)+1);
  return dp[s][e]=cnt;  
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  dp.assign(n, std::vector<int>(n, -1));
  std::cout << solve(0, n-1, v);

  return 0; 
}
// 1003

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<int> dp(41), r_dp(41);
  dp[0]=0;  dp[1]=1;
  r_dp[0]=1;  r_dp[1]=0;
  for (int i=2;i<41;++i) {
    dp[i]=dp[i-1]+dp[i-2];
    r_dp[i]=r_dp[i-1]+r_dp[i-2];
  }

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::cout << r_dp[n] << ' ' << dp[n] << '\n';
  }

  return 0; 
}
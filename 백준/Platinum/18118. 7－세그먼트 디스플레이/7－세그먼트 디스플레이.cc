// 18118 

#include <iostream>
#include <algorithm>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

using ll=long long int;
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, m;  std::cin >> n >> m;
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(m, -1));
    for (int i=0;i<10;++i) dp[0][i%m]=i;
    dp[0][11%m]=11;

    for (int k=0;k<n-1;++k) for (int r=0;r<m;++r) if (dp[k][r]!=-1) {
      for (int i=0;i<10;++i) {
        int nr=(10*r+i)%m;
        dp[k+1][nr]=std::max(dp[k+1][nr], 10LL*dp[k][r]+i);
      }
      int nr=(100*r+11)%m;
      dp[k+1][nr]=std::max(dp[k+1][nr], 100LL*dp[k][r]+11);
    }

    if (dp[n-1][0]==-1) std::cout << "0\n";
    else std::cout << dp[n-1][0] << '\n';
  }
  return 0;
}

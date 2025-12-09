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
    // std::vector<std::vector<ll>> dp(n, std::vector<ll>(m, -1));
    std::vector<ll> dp(m, -1), tmp(m, -1);
    for (int i=0;i<10;++i) dp[i%m]=i;
    dp[11%m]=11;

    
    for (int k=0;k<n-1;++k) {
      std::fill(tmp.begin(), tmp.end(), -1);
      for (int r=0;r<m;++r) if (dp[r]!=-1) {
        for (int i=0;i<10;++i) {
          int nr=(10*r+i)%m;
          tmp[nr]=std::max(tmp[nr], 10LL*dp[r]+i);
        }
        int nr=(100*r+11)%m;
        tmp[nr]=std::max(tmp[nr], 100LL*dp[r]+11);
      }
      dp=tmp;
    }

    if (dp[0]==-1) std::cout << "0\n";
    else std::cout << dp[0] << '\n';
  }
  return 0;
}

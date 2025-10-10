// 34601

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;

  std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(k+1, 0));
  dp[1][0]=1;
  for (int i=1;i<n;++i) for (int j=0;j<=k;++j) {
    dp[i+1][j]+=dp[i][j]*(j+1LL)%MOD;
    dp[i+1][j]%=MOD;
    if (j<k && j<i) dp[i+1][j+1]+=dp[i][j]*(i-j)%MOD, dp[i+1][j+1]%=MOD;
  }
  std::cout << dp[n][k]%MOD;

  return 0;
}
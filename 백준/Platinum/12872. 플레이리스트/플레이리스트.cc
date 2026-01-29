// 12872

#include <iostream>
#include <vector>
#include <string>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, p;  std::cin >> n >> m >> p;

  std::vector<ll> dp(n+1, 0);
  dp[0]=1LL;

  for (int i=1;i<=p;++i) {
    std::vector<ll> tmp(n+1, 0);
    for (int j=1;j<=n;++j) {
      tmp[j]+=dp[j-1]*(n-j+1)%MOD;
      tmp[j]%=MOD;
      if (j>m) tmp[j]+=dp[j]*(j-m)%MOD;
      tmp[j]%=MOD;
    }
    std::swap(dp, tmp);
  }
  std::cout << dp[n]%MOD;
  
  return 0;
}

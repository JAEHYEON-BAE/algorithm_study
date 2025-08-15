// 18305

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

using ll=long long int;

ll DP(int i, int j, std::vector<std::vector<ll>> &dp, const std::vector<ll> &sum)
{
  ll &res=dp[i][j];
  if (res!=-1) return res;
  if (i==j) return res=0;

  ll tmp=(~0uLL)>>1;
  for (int k=i;k<j;++k) {
    tmp=std::min(tmp, DP(i, k, dp, sum)+DP(k+1, j, dp, sum)+sum[j+1]-sum[i]);
  }
  return res=tmp;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<ll> v(n), sum(n+1, 0);
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    sum[i+1]=sum[i]+v[i];
  }

  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, -1));
  std::cout << DP(0, n-1, dp, sum);

  
  return 0;
}


// 17893

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  int N=1<<n;
  std::vector<long double> dp(N, 0.0L), tmp(N, 0.0L);
  dp[N-1]=1.0L;

  
  for (int i=0;i<m;++i) {
    int u, v; long double p;
    std::cin >> u >> v >> p;
    --u,--v;

    std::fill(tmp.begin(), tmp.end(), 0.0L);

    for (int bit=0;bit<N;++bit) {
      bool u_alive=bit&(1<<u);
      bool v_alive=bit&(1<<v);

      if (!u_alive || !v_alive) tmp[bit]+=dp[bit];
      else {
        int success=bit^(1<<v);
        tmp[success]+=dp[bit]*p;
        tmp[bit]+=dp[bit]*(1.0L-p);
      }
    }
    dp.swap(tmp);
  }
  
  std::cout.setf(std::ios::fixed);
  std::cout << std::setprecision(10);
  for (int i=0;i<n;++i) {
    long double ans=0.0L;
    for (int bit=0;bit<N;++bit) {
      if (bit&(1<<i)) ans+=dp[bit];
    }
    std::cout << ans << '\n';
  }
  
  return 0;
}
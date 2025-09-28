// 11726

#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MOD=10'007;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> dp(n+1, 0);
  dp[0]=1;
  dp[1]=1;
  for (int i=2;i<=n;++i) {
    dp[i]=dp[i-2]+dp[i-1];
    dp[i]%=MOD;
  }
  std::cout << dp[n];
  return 0;
}
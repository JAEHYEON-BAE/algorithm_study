// 11058

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long long int> dp(n+1, 0);
  for (int i=1;i<=n;++i) {
    dp[i]=dp[i-1]+1;

    for (int j=1;j<=i-3;++j) {
      long long int buf=dp[j]*(i-j-1);
      dp[i]=std::max(dp[i], buf);
    }
  }
  std::cout << dp[n];
  return 0;
}

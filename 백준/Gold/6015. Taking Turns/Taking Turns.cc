// 6015

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long long int> w(n);
  for (int i=0;i<n;++i) std::cin >> w[i];

  std::vector<std::pair<long long int, long long int>> dp(n);
  dp[n-1]={w[n-1], 0};
  for (int i=n-2;i>=0;--i) {
    std::pair<long long int, long long int> take={w[i]+dp[i+1].second, dp[i+1].first};
    std::pair<long long int, long long int> skip=dp[i+1];
    if (take.first>=skip.first) dp[i]=take;
    else dp[i]=skip;
  }
  std::cout << dp[0].first << ' ' << dp[0].second;
  
  return 0;
}

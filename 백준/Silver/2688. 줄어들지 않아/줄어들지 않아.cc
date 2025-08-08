// 2688

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// n-digit, start with k
long long int DP(int n, int k, std::vector<std::vector<long long int>> &dp)
{
  if (dp[n][k]!=-1) return dp[n][k];
  if (n==1) return dp[1][k]=10-k;

  long long int &res=dp[n][k];
  res=0;
  for (int i=k;i<=9;++i) {
    res+=DP(n-1, i, dp);
  }
  return res;
}
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
 std::vector<std::vector<long long int>> dp(65, std::vector<long long int>(10, -1));
  while (t--) {
    int n;  std::cin >> n;
    std::cout << DP(n, 0, dp) << '\n';
  }
  return 0;
}

// 7433

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  // std::vector<bool> mod(k, 0);

  auto mod=[&k](int x) {
    return ((x%k)+k)%k;
  };
  
  std::vector<std::bitset<100>> dp(n, 0);
  int x;  std::cin >> x;
  dp[0][mod(x)]=1;
  
  for (int i=1;i<n;++i) {
    std::cin >> x;
    for (int j=0;j<k;++j) {
      if (dp[i-1][j]) dp[i][mod(j+x)]=dp[i][mod(j-x)]=1;
    }
  }

  std::cout << ((dp[n-1][0])?"Divisible":"Not divisible");

  return 0;
}

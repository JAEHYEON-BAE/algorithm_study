// 2448
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i)  std::cin >> v[i];

  std::vector<int> dp(n, 1), r_dp(n, 1);
  /* dp = LIS */

  dp[0]=1; r_dp[n-1]=1;
  for (int i=1;i<n;++i) {
    for (int j=0;j<i;++j) if (v[i]>v[j]) {
      dp[i] = std::max(dp[i], dp[j]+1);
    }
  }

  for (int i=n-2;i>=0;--i) {
    for (int j=n-1;j>i;--j) if (v[i]>v[j]) {
      r_dp[i] = std::max(r_dp[i], r_dp[j]+1);
    }
  }

  int result=0;
  for (int k=0;k<n;++k) {
    result = std::max(result, dp[k]+r_dp[k]-1);
  }
  std::cout << result;
 
  return 0; 
}

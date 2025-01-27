// 1126

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> dp(n, std::vector<int>(500'001, -1));
  // dp[i][gap]: i-th block, diff=gap, maximum height
  int block;  std::cin >> block;
  dp[0][0] = 0;
  dp[0][block] = block;

  for (int i=1;i<n;++i) {
    std::cin >> block;
    for (int gap=0;gap<500'001;++gap) {
      if (dp[i-1][gap]!=-1) {
        dp[i][gap] = std::max(dp[i][gap], dp[i-1][gap]);
        dp[i][gap+block] = std::max(dp[i][gap+block], dp[i-1][gap]+block);
        if (gap>=block) dp[i][gap-block] = std::max(dp[i][gap-block], dp[i-1][gap]);
        else dp[i][block-gap] = std::max(dp[i][block-gap], dp[i-1][gap]+block-gap);
      }
    }
  }

  int result;
  if ((result=dp[n-1][0])<= 0) result=-1;
  std::cout << result;
  return 0; 
}

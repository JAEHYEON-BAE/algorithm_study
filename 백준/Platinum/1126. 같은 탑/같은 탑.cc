// 1126

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> dp(500'001, -1), tmp(500'001, -1);
  // dp[i][gap]: i-th block, diff=gap, maximum height
  int block;  std::cin >> block;
  dp[0] = 0;
  dp[block] = block;

  for (int i=1;i<n;++i) {
    std::cin >> block;
    for (int gap=0;gap<500'001;++gap) {
      if (dp[gap]!=-1) {
        tmp[gap] = std::max(tmp[gap], dp[gap]);
        tmp[gap+block] = std::max(tmp[gap+block], dp[gap]+block);
        if (gap>=block) tmp[gap-block] = std::max(tmp[gap-block], dp[gap]);
        else tmp[block-gap] = std::max(tmp[block-gap], dp[gap]+block-gap);
      }
    }
    dp=tmp;
    std::fill(tmp.begin(), tmp.end(), -1);
  }

  int result;
  if ((result=dp[0])<= 0) result=-1;
  std::cout << result;
  return 0; 
}

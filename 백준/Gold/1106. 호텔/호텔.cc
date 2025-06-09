// 1106

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int c, n;  std::cin >> c >> n;

  std::vector<int> dp(c+101, (~0u)>>2);
  dp[0]=0;

  for (int i=0;i<n;++i) {
    int x, y;  std::cin >> x >> y;
    for (int j=y;j<c+101;++j) {
      dp[j]=std::min(dp[j], dp[j-y]+x);
    }
  }
  std::cout << *std::min_element(dp.begin()+c, dp.end());
  return 0;
}

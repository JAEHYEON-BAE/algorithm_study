// 13002

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> h(n);

  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
  for (int i=0;i<n;++i) {
    std::cin >> h[i];
    dp[i][i]=h[i]*n;
  }

  for (int l=1;l<n;++l) {
    for (int i=0;i+l<n;++i) {
      int j=i+l;
      dp[i][j]=std::max(
        h[j]*(n-l)+dp[i][j-1],
        h[i]*(n-l)+dp[i+1][j]
        );
    }
  }
  std::cout << dp[0][n-1];
  return 0;
}
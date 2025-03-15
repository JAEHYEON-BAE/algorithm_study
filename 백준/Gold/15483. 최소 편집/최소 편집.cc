#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::string a, b;  std::cin >> a >> b;
  int n = a.size(), m = b.size();

  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
  // dp[i][j] = minimum edit between a[0:i] and b[0:j]
  for (int i=0;i<=n;++i) dp[i][0] = i;
  for (int j=0;j<=m;++j) dp[0][j] = j;

  for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) {
    if (a[i-1]==b[j-1])  dp[i][j] = dp[i-1][j-1];
    else {
      dp[i][j] = std::min(std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
    }
  }
  std::cout << dp[n][m];
}
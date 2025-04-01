// 15553
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<std::vector<int>> dp(n, std::vector<int>(k+1, INF));
  int t;  std::cin >> t;
  dp[0][1]=1;
  int prev=t;
  for (int i=1;i<n;++i) {
    std::cin >> t;
    for (int j=0;j<=k;++j) {
      if (dp[i-1][j]<INF) {
        if (j<k) dp[i][j+1]=std::min(dp[i][j+1], 1+dp[i-1][j]);
        dp[i][j]=std::min(dp[i][j], t-prev+dp[i-1][j]);
      }
    }
    prev=t;
  }
  std::cout << *std::min_element(dp[n-1].begin(), dp[n-1].end());
}
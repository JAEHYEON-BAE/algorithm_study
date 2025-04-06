// 17208
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

constexpr int INF=(~0u)>>1;
constexpr int nINF=(1<<31);
constexpr int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> dp(m+1, std::vector<int>(k+1, -1));
  dp[m][k]=0;
  int max=0;
  while (n--) {
    int x, y;  std::cin >> x >> y;
    for (int i=0;i<=m;++i) for (int j=0;j<=k;++j) {
      if (dp[i][j]!=-1) {
        if (i>=x && j>=y) {
          dp[i-x][j-y]=std::max(dp[i-x][j-y], 1+dp[i][j]);
          max=std::max(max, dp[i-x][j-y]);
        }
      }
    }
  }
  std::cout << max;
  return 0;
}
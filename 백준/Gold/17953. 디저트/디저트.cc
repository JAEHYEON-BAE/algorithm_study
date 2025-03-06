// 17953

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};
const int MOD = 1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> v(m, std::vector<int>(n));
  for (int i=0;i<m;++i) for (int j=0;j<n;++j) {
    std::cin >> v[i][j];
  }

  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m, 0));
  for (int i=1;i<=n;++i) {
    int tmp=0;
    for (int j=0;j<m;++j) for (int k=0;k<m;++k) {
      int tmp;
      if (i==1 || j!=k) tmp=dp[i-1][k]+v[j][i-1];
      else tmp=dp[i-1][k]+v[j][i-1]/2;
      dp[i][j]=std::max(dp[i][j], tmp);
    }
  }
  std::cout << *std::max_element(dp[n].begin(), dp[n].end());
  
  return 0;
}
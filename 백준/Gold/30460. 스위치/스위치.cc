// 17352

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int x;  std::cin >> x;
  std::vector<std::vector<int>> dp(n, std::vector<int>(4, nINF));
  dp[0][0]=x;
  dp[0][3]=x<<1;

  // for (int k=0;k<4;++k) std::cout << dp[0][k] << ' ';
  // std::cout << std::endl;

  for (int i=1;i<n;++i) {
    std::cin >> x;
    int k=std::max(dp[i-1][0], dp[i-1][1]);
    if (k>nINF) {
      dp[i][0]=std::max(dp[i-1][0], dp[i-1][1]) + x;
      dp[i][3]=std::max(dp[i-1][0], dp[i-1][1]) + (x<<1);
    }
    if (dp[i-1][2]>nINF) dp[i][1]=dp[i-1][2]+(x<<1);
    if (dp[i-1][3]>nINF) dp[i][2]=dp[i-1][3]+(x<<1);
    

    // for (int k=0;k<4;++k) std::cout << dp[i][k] << ' ';
    // std::cout << std::endl;

  }
  std::cout << *std::max_element(dp[n-1].begin(), dp[n-1].end());

  return 0;
}
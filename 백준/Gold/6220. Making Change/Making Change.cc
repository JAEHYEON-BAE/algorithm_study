// 6220
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int c, n;  std::cin >> c >> n;

  std::vector<std::vector<bool>> dp(c+1, std::vector<bool>(c+1, 0));
  dp[0][c]=1;
  int x;
  for (int i=0;i<n;++i) {
    std::cin >> x;
    std::vector<std::vector<bool>> tmp(c+1, std::vector<bool>(c+1, 0));
    for (int f=0;f<=c;++f) for (int s=0;s<=c;++s) {
      if (dp[f][s]) for (int j=0;j<=s/x;++j) {
        dp[f+j][s-j*x]=1;
      }
    }
  }
  for (int i=0;i<=c;++i) {
    if (dp[i][0]) {
      std::cout << i;
      return 0;
    }
  }
  return 0;
}
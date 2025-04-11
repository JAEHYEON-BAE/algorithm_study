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
  std::vector<int> coin(n);
  for (int i=0;i<n;++i) std::cin >> coin[i];
  std::vector<int> dp(c+1, INF);

  dp[0]=0;
  for (int i=0;i<=c;++i) for (int j=0;j<n;++j) {
    if (coin[j]<=i) dp[i]=std::min(dp[i], 1+dp[i-coin[j]]);
  }
  std::cout << dp[c];
  return 0;
}
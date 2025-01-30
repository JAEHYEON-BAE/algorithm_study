// 19686

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<std::vector<int64_t>> dp(n-1, std::vector<int64_t>(21, 0));
  int x;  std::cin >> x;
  dp[0][x]=1;
  for (int i=1;i<n-1;++i) {
    std::cin >> x;
 
    for (int j=0;j<21;++j) {
      if (dp[i-1][j]) {
        if (j+x<=20) dp[i][j+x]+=dp[i-1][j];
        if (j>=x) dp[i][j-x]+=dp[i-1][j];
      }
    }
  }
  int64_t result;  std::cin >> result;
  std::cout << dp[n-2][result];
  
  return 0; 
}

// 33148
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> map(n*n);
  for (int i=0;i<n*n;++i) std::cin >> map[i];

  std::vector<std::vector<int>> dp(n*n, std::vector<int>(3, 0));
  /** 0: horizontal
      1: vertical
      2: diagonal 
    */
  dp[1][0]=1;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    
    if (i<2 && j<2) continue;
    if (map[i*n+j]==1) continue;
    
    if (j>=1) dp[i*n+j][0] += dp[i*n+(j-1)][0]+dp[i*n+(j-1)][2];
    if (i>=1) dp[i*n+j][1] += dp[(i-1)*n+j][1]+dp[(i-1)*n+j][2];
    if (i>=1 && j>=1 && map[(i-1)*n+j]==0 && map[i*n+(j-1)]==0)
      dp[i*n+j][2] += dp[(i-1)*n+(j-1)][0]
                    + dp[(i-1)*n+(j-1)][1]
                    + dp[(i-1)*n+(j-1)][2];

  }

  std::cout << dp[n*n-1][0]+dp[n*n-1][1]+dp[n*n-1][2];
  
  return 0; 
}

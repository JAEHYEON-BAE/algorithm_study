// 16565

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int MOD=10'007;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  if (n<4) {std::cout << '0'; return 0;}

  int dp[53][53];
  for (int i=0;i<53;++i) {
    dp[i][0]=1;
    dp[i][i]=1;
    for (int j=1;j<i;++j) {
      dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
      dp[i][i-j]=dp[i][j];
    }
  }

  int res=0;
  for (int i=4;i<=n;i+=4) {
    if ((i/4)&1) res+=dp[13][i/4]*dp[52-i][n-i];
    else res-=dp[13][i/4]*dp[52-i][n-i];
    res%=MOD;
  }
  if (res<0) res+=MOD;
  std::cout << res;
  
  return 0;
}

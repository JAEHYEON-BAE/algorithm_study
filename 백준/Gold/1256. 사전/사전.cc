// 1256

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

constexpr int MAX=(~0u)>>2;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> dp(n+m+1, std::vector<int>(n+m+1, 0));
  for (int i=0;i<=n+m;++i) {
    dp[i][0]=dp[i][i]=1;
    for (int j=1;j<i;++j) {
      dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
      if (dp[i][j]>MAX) dp[i][j]=MAX;
    }
  }

  if (dp[n+m][m]<k) {
    std::cout << "-1";
    return 0;
  }

  while (n>0 || m>0) {
    if (m==0) {
      while (n--) std::cout << 'a';
      return 0;
    }
    if (n==0) {
      while (m--) std::cout << 'z';
      return 0;
    }

    int tmp=dp[n+m-1][n-1];
    if (k<=tmp) {
      std::cout << 'a';
      --n;
    }
    else {
      std::cout << 'z';
      --m;
      k-=tmp;
    }
  }
  return 0;
}

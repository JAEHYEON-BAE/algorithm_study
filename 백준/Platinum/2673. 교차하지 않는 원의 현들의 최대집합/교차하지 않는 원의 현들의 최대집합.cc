// 2673

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> pair(101, -1);
  for (int i=0;i<n;++i) {
    int a, b;  std::cin >> a >> b;
    pair[a]=b;
    pair[b]=a;
  }

  std::vector<std::vector<int>> dp(101, std::vector<int>(101, 0));
  for (int len=1;len<=100;++len) {
    int l=1, r;
    for (;(r=l+len-1)<=100;++l) {
      dp[l][r]=dp[l][r-1];
      int k=pair[r];
      if (k!=-1 && k>=l && k<r) {
        int tmp=1;
        if (k+1<=r-1) tmp+=dp[k+1][r-1];
        if (l<=k-1) tmp+=dp[l][k-1];
        dp[l][r]=std::max(dp[l][r], tmp);
      }
    }
  }
  std::cout << dp[1][100];
  return 0;
}
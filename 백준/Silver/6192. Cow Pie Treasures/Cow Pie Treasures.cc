// 6192

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // dp[r][c]=v[r][c]+max(dp[r-1][c-1], dp[r][c-1], dp[r+1][c-1])

  int r, c;  std::cin >> r >> c;
  std::vector<std::vector<int>> v(r, std::vector<int>(c));
  for (auto &r:v) for (int &x:r) std::cin >> x;

  // tmp[r]=v[r][c]+max(dp[r-1], dp[r], dp[r+1])
  std::vector<int> dp(r, 0), tmp(r);

  dp[0]=v[0][0];
  for (int j=1;j<c;++j) {
    for (int i=0;i<r;++i) {
      int k=std::max({(i?dp[i-1]:0), dp[i], (i<r-1?dp[i+1]:0)});
      if (k==0) tmp[i]=0;
      else tmp[i]=v[i][j]+k;
    }

    std::swap(tmp, dp);
  }
  std::cout << dp[r-1];
  
  return 0;
}
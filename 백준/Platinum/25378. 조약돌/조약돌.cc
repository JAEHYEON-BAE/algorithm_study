// 25378

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<int> v(n);
  for (int &i:v) std::cin >> i;

  std::vector<std::vector<bool>> one(n, std::vector<bool>(n, 0));

  for (int l=0;l<n-1;++l) {
    bool FLAG=1;
    int prev=v[l];
    for (int r=l;r<n;++r) {
      if (prev==v[r]) one[l][r]=FLAG;
      else {
        one[l][r]=0;
        if (prev>v[r]) FLAG=0;
        prev=std::abs(prev-v[r]);
      }
      // std::cout << l << ' ' << r << ' ' << one[l][r] << '\n';
    }
  }

  std::vector<int> dp(n, 0);
  dp[0]=1;
  for (int r=1;r<n;++r) {
    dp[r]=dp[r-1]+1;
    for (int l=0;l<r;++l) {
      if (one[l][r]) {
        dp[r]=std::min(dp[r], (l?dp[l-1]:0)+r-l);
      }
    }
    // std::cout << "dp[" << r << "] = " << dp[r] << '\n';
  }
  
  std::cout << dp[n-1];
  return 0;
}


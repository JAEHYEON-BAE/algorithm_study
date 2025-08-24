// 1958

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string a, b, c;  std::cin >> a >> b >> c;
  int n=a.size(), m=b.size(), l=c.size();
  std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(m+1, std::vector<int>(l+1, 0)));
  
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) for (int k=0;k<l;++k) {
    if (a[i]==b[j] && b[j]==c[k]) dp[i+1][j+1][k+1]=dp[i][j][k]+1;
    else {
      dp[i+1][j+1][k+1]=std::max({dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k]});
    }
  }

  std::cout << dp[n][m][l]; 
  return 0;
}


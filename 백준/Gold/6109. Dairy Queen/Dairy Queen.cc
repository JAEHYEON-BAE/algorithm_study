// 6109

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int DP(int idx, int n, std::vector<std::vector<int>> &dp, const std::vector<int> &v)
{
  if (idx>=v.size()) return 0;
  int &tmp=dp[idx][n];
  if (tmp!=-1) return tmp;

  tmp=0;
  int k=n/v[idx];
  for (int i=0;i<=k;++i) tmp+=DP(idx+1, n-i*v[idx], dp, v);
 
  return tmp;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, c;  std::cin >> n >> c;
  std::vector<int> v(c);
  for (int &i:v) std::cin >> i;

  std::vector<std::vector<int>> dp(c, std::vector<int>(n+1, -1));

  for (int i=0;i<c;++i) dp[i][0]=1;
  for (int i=1;v.back()*i<=n;++i) dp[c-1][v.back()*i]=1;
  
  std::cout << DP(0, n, dp, v);


  return 0;
}


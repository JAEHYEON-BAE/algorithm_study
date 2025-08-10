// 1139

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cmath>

inline long double area(int i, int j, int k, const std::vector<int> &v) 
{
  long double a=v[i], b=v[j], c=v[k];
  long double s=0.5L*(a+b+c);
  return std::sqrt(s*(s-a)*(s-b)*(s-c));
}

inline bool valid_tri(int i, int j, int k, const std::vector<int> &v) 
{
  return v[i]+v[j]+v[k]>std::max({v[i], v[j], v[k]})<<1;
}

long double DP(int x, std::vector<long double> &dp, const int &n, const std::vector<int> &v)
{
  if (x==0) return dp[x]=0;
  if (dp[x]>-1.0L) return dp[x];
  
  long double &res=dp[x];

  int i=__builtin_ctz(x);
  res=DP(x^(1<<i), dp, n, v);
  for (int j=i+1;j<n;++j) if (x&(1<<j)) for (int k=j+1;k<n;++k) if (x&(1<<k)) if (valid_tri(i, j, k, v)) {
    res=std::max(res, area(i, j, k, v)+DP(x^(1<<i)^(1<<j)^(1<<k), dp, n, v));
  }
  return res;
}
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  if (n<3) {
    std::cout << "0.0";
    return 0;
  }
  for (int i=0;i<n;++i) std::cin >> v[i];
    
  std::vector<long double> dp(1<<n, -1);
  std::cout << std::fixed << std::setprecision(10) << DP((1<<n)-1, dp, n, v);
  
  
  return 0;
}

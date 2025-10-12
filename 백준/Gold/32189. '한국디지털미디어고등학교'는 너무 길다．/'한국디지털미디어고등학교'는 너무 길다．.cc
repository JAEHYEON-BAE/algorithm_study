// 32189

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

inline int c2i(const char &c) {
  if (c>='a' && c<='z') return c-'a';
  else return c-'A'+26;
}

int LCS(const std::string &a, const std::string &b) {
  int n=a.size(), m=b.size();
  std::vector<std::vector<int>> dp(n, std::vector<int>(m,0));
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    if (a[i]==b[j]) dp[i][j]=1+(i&&j?dp[i-1][j-1]:0);
    else dp[i][j]=std::max(i?dp[i-1][j]:0, j?dp[i][j-1]:0);
  }
  return dp[n-1][m-1];
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int n=s.size();

  if (n==1) {
    std::cout << '0';
    return 0;
  }

  int a=n>>1;
  int b=n-a;

  int tmp=std::min(a, b)-LCS(s.substr(0, a), s.substr(a));
  if (n&1) {
    std::swap(a, b);
    tmp=std::max(tmp, std::min(a, b)-LCS(s.substr(0, a), s.substr(a)));
  }
  std::cout << tmp;
  
  return 0;
}
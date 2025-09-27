// 33224

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::string> dp(m, "");
  for (int i=0;i<n;++i) {
    std::string s; std::cin >> s;
    for (int j=0;j<m;++j) if (s[j]=='*') dp[j]="x";

    if (i==n-1) break;
    
    std::vector<std::string> tmp(m, "x");
    for (int j=0;j<m;++j) {
      if (dp[j]!="x") tmp[j]=dp[j]+'F';
      else if (j && dp[j-1]!="x") tmp[j]=dp[j-1]+'R';
      else if (j<m-1 && dp[j+1]!="x") tmp[j]=dp[j+1]+'L';
    }

    dp.swap(tmp);
  }

  for (int i=0;i<m;++i) if (dp[i]!="x") {
    std::string ans=dp[i];

    int curr=i;
    for (int j=ans.size()-1;j>=0;--j) {
      if (ans[j]=='F') continue;
      else if (ans[j]=='L') ++curr;
      else if (ans[j]=='R') --curr;
    }
    
    std::cout << curr+1 << '\n' << ans;
    return 0;
  }
  std::cout << "impossible";
  return 0;
}
// 27083

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n), dp(n), len(n);

  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    len[i]=1, dp[i]=1;
    for (int j=0;j<i;++j) {
      if (v[i]<v[j]) {
        if (len[i]==len[j]+1) dp[i]+=dp[j];
        else if (len[i]<len[j]+1) len[i]=len[j]+1, dp[i]=dp[j];
      }
      else if (v[i]==v[j]) dp[j]=0;
    }
  }

  int ans=0, cnt=0;
  for (int i=0;i<n;++i) {
    if (len[i]>ans) ans=len[i], cnt=dp[i];
    else if (len[i]==ans) cnt+=dp[i];
  }
  std::cout << ans << ' ' << cnt;
  return 0;
}

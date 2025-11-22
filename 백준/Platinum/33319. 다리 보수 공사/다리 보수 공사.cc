#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <string>
using namespace std;

using ll=long long int;
constexpr ll MOD=1'000'000'007;


array<int, 2> roadwork(string s){
  int n=s.size();
  std::vector<int> rev(n+1, -1);
  int la=-1, lb=-1;
  for (int i=0;i<n;++i) {
    if (s[i]=='A') la=i;
    else lb=i;
    rev[i+1]=std::min(la, lb);
  }

  std::vector<int> dp(n+1, 0);
  std::vector<ll> cnt(n+1, 0);
  dp[0]=1, cnt[0]=1;

  for (int i=1;i<=n;++i) {
    int pos=rev[i];
    if (pos==-1) {
      dp[i]=dp[i-1];
      cnt[i]=cnt[i-1];
    }
    else {
      dp[i]=1+dp[pos];
      cnt[i]=cnt[pos];
    }

    if (dp[i]<dp[i-1]) dp[i]=dp[i-1], cnt[i]=cnt[i-1];
    else if (dp[i]==dp[i-1]) cnt[i]+=cnt[i-1], cnt[i]%=MOD;
  }

  return {dp[n], static_cast<int>(cnt[n]%MOD)};
}

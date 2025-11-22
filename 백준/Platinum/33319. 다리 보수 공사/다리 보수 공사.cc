#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <string>
using namespace std;

using ll=long long int;
constexpr ll MOD=1'000'000'007;


array<int, 2> roadwork(string s){
  std::vector<int> rev;
  int n=s.size();
  for (int i=0;i<n-1;++i) if (s[i]!=s[i+1]) rev.push_back(i);

  std::vector<int> dp(n+1, 0);
  std::vector<ll> cnt(n+1, 0);
  dp[0]=1, cnt[0]=1;

  for (int i=1;i<=n;++i) {

    int v; ll c;
    auto pos=std::lower_bound(rev.begin(), rev.end(), i-1);
    if (pos==rev.begin()) {
      dp[i]=dp[i-1];
      cnt[i]=cnt[i-1];
    }
    else {
      int idx=*(pos-1);
      dp[i]=1+dp[idx];
      cnt[i]=cnt[idx];
    }

    if (dp[i]==dp[i-1]) cnt[i]+=cnt[i-1], cnt[i]%=MOD;
    // std::cerr << "i=" << i << ", " << dp[i] << ' ' << cnt[i] << '\n';
  }

  return {dp[n], static_cast<int>(cnt[n]%MOD)};
}

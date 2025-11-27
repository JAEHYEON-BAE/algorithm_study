// 24231

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

int RECUR(int l, int r, const std::string &s, std::vector<std::vector<ll>> &dp)
{
  if (l>=s.size() || r>=s.size()) return 0;
  ll &res=dp[l][r];
  if (res!=-1) return res;
  
  if (l>=r) return res=0;
  
  int cnt0=0, cnt1=0;
  for (int i=l;i<=r;++i) s[i]=='0'?++cnt0:++cnt1;
  if (cnt0!=cnt1) return res=0;

  if (l+1==r) return res=1;

  res=0;
  for (int i=l+1;i<=r;i+=2) if (s[l]!=s[i]) {
    res+=(l+1<i-1?RECUR(l+1, i-1, s, dp):1LL)*(i+1<r?RECUR(i+1, r, s, dp):1LL)%MOD;
    res%=MOD;
  }

  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int cnt0=0, cnt1=0;
  for (const char &c:s) c=='0'?++cnt0:++cnt1;
  if (cnt0!=cnt1) {
    std::cout << '0';
    return 0;
  }
  int n=s.size();
  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, -1));
  std::cout << RECUR(0, n-1, s, dp) << '\n';

  return 0;
}
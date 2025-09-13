// 30398

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007LL;

ll mod_exp(ll a, ll r)
{
  if (a==0LL) return 0LL;
  else if (a==1LL) return 1LL;
  
  ll res=1LL;
  while (r) {
    if (r&1) res*=a, res%=MOD;
    a*=a, a%=MOD;
    r>>=1;
  }
  return res%MOD;
}
ll mod_inv(ll a)
{
  if (a==0LL) return 1LL;
  return mod_exp(a, MOD-2)%MOD;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, d, p;  std::cin >> n >> d >> p;

  // To find: (1, 1, .. , 1) ~ (n, n, .. , n) distance

  // prep
  std::vector<ll> facts(1'000'001), inv_facts(1'000'001);
  facts[0]=facts[1]=inv_facts[0]=1;
  for (ll i=2;i<=1'000'000;++i) facts[i]=facts[i-1]*i%MOD;
  
  inv_facts[1'000'000]=mod_inv(facts[1'000'000]);
  
  for (ll i=1'000'000;i>0;--i) inv_facts[i-1]=inv_facts[i]*i%MOD;
  
  ll ans=1LL;
  std::vector<ll> curr(d, 1);
  for (int i=0;i<=p;++i) {
    std::vector<ll> gap(d);
    ll sum=0LL;
    if (i==p) for (int j=0;j<d;++j) {
      gap[j]=std::abs(n-curr[j])%MOD;
      sum+=gap[j];
      sum%=MOD;
    }
    else for (int j=0;j<d;++j) {
      ll x;  std::cin >> x;
      gap[j]=std::abs(x-curr[j])%MOD;
      sum+=gap[j];
      sum%=MOD;
      curr[j]=x;
    }
    ll tmp=facts[sum];
    for (int j=0;j<d;++j) {
      tmp*=inv_facts[gap[j]];
      tmp%=MOD;
    }
    ans*=tmp;
    ans%=MOD;
  }
  std::cout << ans;
  return 0;
}
// 12038

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;
constexpr ll MOD=1'000'000'007;

ll mod_exp(ll a, ll r)
{
  ll tmp=1LL;
  while (r) {
    if (r&1) tmp=tmp*a%MOD;
    a=a*a%MOD;
    r>>=1;
  }
  return tmp;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  ll facts[16];
  facts[0]=facts[1]=1;
  for (ll i=2;i<=15;++i) facts[i]=facts[i-1]*i;
  
  int t;  std::cin >> t;
  for (int tc=1;tc<=t;++tc) {
    ll c, v, l;  std::cin >> c >> v >> l;
    ll res=0;
    for (int k=0;(k<<1)<=l;++k) {
      res+=mod_exp(c*v, k)*mod_exp(v, l-(k<<1))%MOD*(facts[l-k]/facts[k]/facts[l-(k<<1)]%MOD)%MOD;
      res%=MOD;
    }
    std::cout << "Case #" << tc << ": " << res << '\n';
  }
  
  return 0;
}
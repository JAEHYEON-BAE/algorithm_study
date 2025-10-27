// 20791

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

ll mod_exp(ll a, int r)
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

  int n;
  ll x;  
  while (std::cin >> n >> x) {
    std::vector<ll> a(n), b(n);
    for (ll &i:a) std::cin >> i;
    for (ll &i:b) std::cin >> i;

    ll sum=0;
    for (int i=0;i<n;++i) sum=(sum+a[i]*b[i]%MOD)%MOD;
    std::cout << (x+sum)%MOD*mod_exp(x, n-1)%MOD << '\n';
  }
  
  
  return 0;
}
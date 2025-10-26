// 29093

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

ll mod_pow(ll a, ll r)
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

  ll k;  std::cin >> k;

  ll r0=0;
  int tmp=1;
  while (tmp!=3) {
    tmp*=10;
    tmp%=29;
    ++r0;
  }
  ll r=r0+(k-1LL)*28LL;

  ll x=(6*mod_pow(10, r)-18+MOD)%MOD*mod_pow(29, MOD-2)%MOD;
  std::cout << (x*10+6)%MOD;
  return 0;
}
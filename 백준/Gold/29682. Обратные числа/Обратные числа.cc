// 29682

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
ll mod_exp(ll a, int r, ll MOD)
{
  ll tmp=1;
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

  ll a, m;  std::cin >> a >> m;
  std::cout << mod_exp(a, m-2, m);
  return 0;
}
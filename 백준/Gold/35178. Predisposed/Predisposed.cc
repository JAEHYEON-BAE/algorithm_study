// 35178

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

using ll=long long int;

constexpr ll MOD=998'244'353;

ll exp_mod(ll a, ll r)
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

  int n, m, q;  std::cin >> n >> m >> q;
  std::cout << exp_mod(m, n-q);
  return 0;
  // for (int i=0;i<q;++i) {
  //   int x, y; std::cin >> x >> y;
  // }
  // return 0;
}


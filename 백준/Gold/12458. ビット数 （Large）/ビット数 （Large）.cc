// 12458

#include <iostream>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int k=1;k<=t;++k) {
    ll n;  std::cin >> n;

    int msb=64-__builtin_clzll(n);
    ll a=(1LL<<(msb-1))-1;

    std::cout << "Case #" << k << ": " << __builtin_popcountll(a)+__builtin_popcountll(n-a) << '\n';
  }

  return 0;
}


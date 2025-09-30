// 1011

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    ll x, y;  std::cin >> x >> y;
    ll d=0;
    int cnt=0;
    for (ll i=1ll;;++i) {
      d+=i<<1;
      cnt+=2;
      if (d-i>=y-x) {std::cout << cnt-1 << '\n'; break;}
      else if (d>=y-x) {std::cout << cnt << '\n'; break;}
    }
  }
  return 0;
}
// 26014

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

inline void q(ll t, ll &x)
{
  std::cout << "? " << t << std::endl;
  std::cin >> x;
}
int main() 
{
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(nullptr); 
  // std::cout.tie(nullptr);
  ll x;
  q(2, x);
  if (x==0) {
    q(3, x);
    if (x==0) std::cout << "! 1" << std::endl;
    else if (x==1) std::cout << "! 2" << std::endl;
    else assert(!"CASE 1");
    return 0;
  }

  ll t=4;
  ll cnt=1;
  while (cnt++<=42) {
    q(t, x);
    if (x<t/2) {
      std::cout << "! " << t-x << std::endl;
      return 0;
    }
    else if (x==t) t<<=1;
    else assert(!"CASE 2");
  }
  return 0;
}
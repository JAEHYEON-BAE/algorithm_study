// 9714

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    ll n;  std::cin >> n;
    if (n==1) {std::cout << "(0,0)\n"; continue;}
    ll r, c;

    ll k=0;
    while (1) {
      ll t=2LL*k+1LL;
      if (t*t<n) ++k;
      else break;
    }

    ll d=(2LL*k+1LL)*(2LL*k+1LL)-n;
    
    if (d<2*k) r=-k, c=k-d;
    else if (d<4*k) d-=2*k, r=-k+d, c=-k;
    else if (d<6*k) d-=4*k, r=k, c=-k+d;
    else if (d<8*k) d-=6*k, r=k-d, c=k;
    else assert(!"INVALID d");

    std::cout << '(' << r << ',' << c << ")\n";
  }

  return 0;
}
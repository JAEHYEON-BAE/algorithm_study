// 30923

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

  int n;  std::cin >> n;
  std::vector<ll> h(n);
  ll ans=0;
  for (int i=0;i<n;++i) {
    std::cin >> h[i];
    ans+=(h[i]+1)<<1;
    if (i && h[i]>h[i-1]) ans+=h[i]-h[i-1];
  }
  for (int i=n-2;i>=0;--i) if (h[i]>h[i+1]) ans+=h[i]-h[i+1];

  ans+=h.front()+h.back();
  std::cout << ans;
  return 0;
}
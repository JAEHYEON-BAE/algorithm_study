// 14419

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q; ll s, t;  std::cin >> n >> q >> s >> t;
  std::vector<ll> a(n+1), d(n+1);
  for (int i=0;i<=n;++i) std::cin >> a[i];
  ll res=0LL;
  for (int i=1;i<=n;++i) {
    d[i]=a[i]-a[i-1];
    if (d[i]>0) res-=s*d[i];
    else res-=t*d[i];
  }

  for (int i=0;i<q;++i) {
    int l, r; ll x;  std::cin >> l >> r >> x;
    if (d[l]>0) {
      if (d[l]+x>0) res-=s*x;
      else res=res+s*d[l]-t*(d[l]+x);
    }
    else {
      if (d[l]+x>0) res=res+t*d[l]-s*(d[l]+x);
      else res-=t*x;
    }
    d[l]+=x;

    if (r+1<=n) {
      if (d[r+1]>0) {
        if (d[r+1]-x>0) res-=s*(-x);
        else res=res+s*d[r+1]-t*(d[r+1]-x);
      }
      else {
        if (d[r+1]-x>0) res=res+t*d[r+1]-s*(d[r+1]-x);
        else res+=t*x;
      }
      d[r+1]-=x;
    }
    
    
    std::cout << res << '\n';
  }
  return 0;
}
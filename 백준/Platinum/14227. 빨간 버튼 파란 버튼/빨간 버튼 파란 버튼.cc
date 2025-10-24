// 14227

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

  ll a, b, c, d;  std::cin >> a >> b >> c >> d;
  if (a==c && b==d) {
    std::cout << '0';
    return 0;
  }
  else if (a==c || b==d) {
    std::cout << "-1";
    return 0;
  }

  ll p=0, q=0;
  if (a==b && c==d) {
    while ((a<<1)<=c) {
      a<<=1;
      ++p;
    }
    q=c-a;
  }
  else if (a==b || c==d) {
    std::cout << "-1";
    return 0;
  }
  else {
    ll m=a-b, n=c-d;
    if ((m<0 && n>0) || (m>0 && n<0) || n%m!=0) {
      std::cout << "-1";
      return 0;
    }

    ll t=n/m;
    while (t>1) {
      if (t&1LL) {
        std::cout << "-1";
        return 0;
      }
      t>>=1, ++p;
    }

    q=c-(a<<p);
  }

  // std::cerr << p << ' ' << q << std::endl;
  
  if (q<0) {
    std::cout << "-1";
    return 0;
  }
  
  ll cnt=p;
  for (ll t=(1LL<<p);t;t>>=1) {
    cnt+=q/t;
    q=q%t;
  }
  std::cout << cnt;
  return 0;
}
// 1722

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

  int n, q;  std::cin >> n >> q;

  std::vector<ll> fact(n+1, 1);
  for (int i=1;i<=n;++i) fact[i]=fact[i-1]*i;
  
  if (q==1) {
    ll k;  std::cin >> k;
    --k;
    std::vector<int> num(n);
    for (int i=0;i<n;++i) num[i]=i+1;
    
    for (int i=n-1;i>=0;--i) {
      int x=k/fact[i];
      k%=fact[i];

      std::cout << num[x] << ' ';
      num.erase(num.begin()+x);
    }
  }
  else {
    std::vector<bool> used(n+1, 0);
    ll tmp=1;
    for (int i=0;i<n;++i) {
      int x;  std::cin >> x;
      ll cnt=0;
      for (int j=1;j<x;++j) if (!used[j]) ++cnt;
      tmp+=cnt*fact[n-1-i];
      used[x]=1;
    }
    std::cout << tmp;
  }

  return 0;
}
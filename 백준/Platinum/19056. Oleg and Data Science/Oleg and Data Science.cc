// 19056

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


  ll l, r, q;  std::cin >> l >> r >> q;

  if (r<q) {std::cout << "infinity"; return 0;}

  std::vector<bool> is_prime(1'000'001, 1);
  std::vector<int> primes;
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<=1'000'000;++i) {
    if (is_prime[i]) for (int j=i*i;j<=1'000'000;j+=i) is_prime[j]=0;
  }

  for (int i=2;i<=1'000'000;++i) if (is_prime[i]) primes.push_back(i);

  if (l/q==r/q) q*=l/q;

  ll cnt=1;
  for (const int &p:primes) {
    ll tmp=0;
    while (!(q%p)) q/=p, ++tmp;
    cnt*=tmp+1LL;
  }
  if (q!=1) cnt<<=1;

  std::cout << cnt;
  return 0;
}
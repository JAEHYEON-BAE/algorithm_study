// 5615

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

std::array<bool, 100'000> is_prime;
void init() {
  std::fill(is_prime.begin(), is_prime.end(), 1);
  is_prime[0]=is_prime[1]=0;

  for (int i=2;i*i<100'000;++i) if (is_prime[i]) {
    for (int j=i*i;j<100'000;j+=i) is_prime[j]=0;
  }
}

inline uint mod_mul(uint a, uint b, const uint &MOD)
{
  return static_cast<uint>(static_cast<unsigned long long int>(a)*static_cast<unsigned long long int>(b)%static_cast<unsigned long long int>(MOD));
}

uint mod_exp(uint a, uint r, const uint &MOD) 
{
  uint result=1;
  while (r) {
    if (r&1) result=mod_mul(result, a, MOD);
    a=mod_mul(a, a, MOD);
    r>>=1;
  }
  return result%MOD;
}

constexpr uint a[3]={2, 7, 61};
bool miller_rabin(uint n)
{
  // deterministic in 32-bit integer
  if (n<100'000) return is_prime[n];
  if (!(n&1)) return 0;

  uint t=0, u=n-1;
  while (!(u&1)) {u>>=1;++t;}

  for (int i=0;i<3;++i) {
    uint base=a[i];
    assert(base!=1 && base!=n-1);
    
    uint prev, curr=mod_exp(base, u, n);

    for (int i=1;i<=t;++i) {
      prev=curr;
      curr=mod_mul(prev, prev, n);

      if (curr==1 && prev!=1 && prev!=n-1) return 0;
    }

    if (curr!=1) return 0;
  }
  return 1;
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  init();
  int n;  std::cin >> n;
  
  // 2xy+x+y == (x+1)(y+1)-1
  // if 2xy+x+y+1 is prime, it is not valid
  int cnt=0;
  uint area;
  while (n--) {
    std::cin >> area;
    if (miller_rabin(1+(area<<1))) ++cnt;
  }
  std::cout << cnt;

  return 0;
}

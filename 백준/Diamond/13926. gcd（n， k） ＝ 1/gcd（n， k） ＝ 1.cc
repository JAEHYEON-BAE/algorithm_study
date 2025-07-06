// 13926

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <array>

static std::array<bool, 100'000> is_prime;
void init() {
  std::fill(is_prime.begin(), is_prime.end(), 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<100'000;++i) if (is_prime[i]) {
    for (int j=i*i;j<100'000;j+=i) is_prime[j]=0;
  }
  return;
}

inline long long int mod_mul(long long int a, long long int b, const long long int &MOD)
{
  return static_cast<long long int>(static_cast<__int128>(a)*b%MOD);
}

long long int mod_exp(long long int a, long long int r, const long long int &MOD)
{
  long long int result=1LL;
  while (r) {
    if (r&1) result=mod_mul(result, a, MOD);
    a=mod_mul(a, a, MOD);
    r>>=1;
  }
  return result;
}

constexpr long long int a[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller_rabin(long long int n)
{
  if (n==2 || n==3) return 1;
  else if (!(n&1)) return 0;
  else if (n<100'000) return is_prime[n];

  long long int u=n-1, t=0;
  while (!(u&1)) u>>=1, ++t;

  for (int i=0;i<12;++i) {
    long long int base=a[i];
    if (base==n) return 1;
    if (base>n) break;

    long long int prev=0, curr=mod_exp(base, u, n);
    if (curr==1 || curr==n-1) continue;
    
    for (int j=1;j<=t;++j) {
      prev=curr;
      curr=mod_mul(prev, prev, n);

      if (curr==1 && prev!=1 && prev!=n-1) return 0;
    }
    
    if (curr!=1) return 0;
  }
  return 1;
}

long long int GCD(long long int a, long long int b)
{
  if (a<b) std::swap(a, b);
  while (b) {
    long long int tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

long long int pollard_rho(long long int n)
{
  if (!(n&1)) return 2;
  if (miller_rabin(n)) return n;

  long long int x=rand()%(n-2)+2;
  long long int y=x;
  long long int c=rand()%(n-3)+1;

  auto f=[&n, &c](long long int v) {
    return static_cast<long long int>((static_cast<__int128>(v)*v+c)%n);
  };

  long long int d=1;
  while (d==1) {
    x=f(x);
    y=f(f(y));
    d=GCD(std::abs(x-y), n);
    if (d==n) return pollard_rho(n);
  }

  return (miller_rabin(d)?d:pollard_rho(d));
}

void prime_factorization(long long int n, std::set<long long int> &factors)
{
  while (n>1) {
    long long int d=pollard_rho(n);
    factors.insert(d);
    n/=d;
  }
}

long long int phi(long long int n)
{
  if (n==1) return 1;
  if (miller_rabin(n)) return n-1;
  
  std::set<long long int> factors;
  prime_factorization(n, factors);

  for (const auto &f:factors) {
    n=n-n/f;
  }
  return n;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  init();

  long long int n;  std::cin >> n;
  /** Euler Phi Function:
    * 
    * phi(mn)=phi(m)phi(n)
    * phi(p^k)=p^k - p^{k-1}
    * 
    * phi(n)=n * product(1 - 1/p) for every prime factor p of n
    * 
    */
  std::cout << phi(n);

  return 0;
}
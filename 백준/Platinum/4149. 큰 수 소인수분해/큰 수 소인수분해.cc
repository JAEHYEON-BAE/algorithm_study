// 4149

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

long long int mod_mul(long long int a, long long int b, const long long int &MOD)
{
  a%=MOD;
  b%=MOD;
  long long int result=0;
  while (b) {
    if (b&1) result=(result+a)%MOD;
    a=(a<<1)%MOD;
    b>>=1;
  }
  return result%MOD;
}
long long int mod_exp(long long int a, long long int r, const long long int &MOD)
{
  a%=MOD;
  long long int result=1;
  while (r) {
    if (r&1) result=mod_mul(result, a, MOD)%MOD;
    a=mod_mul(a, a, MOD)%MOD;
    r>>=1;
  }
  return result%MOD;
}

bool Miller_Rabin(const long long int n)
{
  if (n==1) return 0;
  else if (n==2) return 1;
  else if (!(n&1)) return 0;
  
  const long long int a[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

  long long int u=n-1, t=0;
  while (!(u&1)) {
    ++t;
    u>>=1;
  }

  bool COMPOSITE_FLAG=0;
  for (int i=0;i<12;++i) {
    long long int base=a[i]%n;
    if (base==0 || base==1) continue;
    
    long long int prev, curr=mod_exp(base, u, n);
    for (int k=1;k<=t;++k) {
      prev=curr;
      curr=mod_mul(prev, prev, n);
      if (prev!=1 && prev!=n-1 && curr==1) {
        COMPOSITE_FLAG=1;
        break;
      }
    }
    if (COMPOSITE_FLAG) break;
    if (curr!=1) {
      COMPOSITE_FLAG=1;
      break;
    }
  }
  return !COMPOSITE_FLAG;
}

long long int GCD(long long int a, long long int b)
{
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

  std::mt19937_64 RNG(std::random_device{}());
  long long int x=RNG()%(n-2)+2;
  long long int y=x;
  long long int c=RNG()%(n-1)+1;
  long long int d=1;

  auto f=[&n, &c](long long int v) -> long long int {
    return static_cast<long long int>((static_cast<__int128>(v)*v+c)%n);
  };

  while (d==1) {
    x=f(x);
    y=f(f(y));
    d=GCD(std::abs(x-y), n);
    if (d==n) return pollard_rho(n);
  }

  return d;  
}

void prime_factorization(long long int n, std::set<long long int> &factors) {
  if (n==1) return;
  if (Miller_Rabin(n)) {
    factors.insert(n);
    return;
  }

  long long int d=pollard_rho(n);
  prime_factorization(d, factors);
  prime_factorization(n/d, factors);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int n;  std::cin >> n;
  std::set<long long int> factors;
  prime_factorization(n, factors);

  for (auto &f:factors) std::cout << f << '\n';

  return 0;
}

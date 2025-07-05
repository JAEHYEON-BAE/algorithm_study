// 1770

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

long long int mod_exp(__int128 a, __int128 r, const __int128 &MOD)
{
  a%=MOD;
  __int128 result=1;
  while (r) {
    if (r&1) result=result*a%MOD;
    a=a*a%MOD;
    r>>=1;
  }
  return static_cast<long long int>(result);
}

bool miller_rabin(long long int n, long long int base)
{
  if (base%n==0) return 1;
  long long int u=n-1;
  while (1) {
    long long int tmp=mod_exp(base, u, n);
    if (tmp==n-1) return 1;
    if (u&1) return (tmp==1 || tmp==n-1);
    u>>=1;
  }
}

constexpr long long int a[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool prime(long long int n)
{
  assert(n>0);
  if (n==2 || n==3) return 1;
  if (!(n&1)) return 0;
  // if (n<1'000'000) return is_prime[n];

  for (int i=0;i<12;++i) {
    if (!miller_rabin(n, a[i])) {
      return 0;
      break;
    }
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

long long int pollard_rho(__int128 n)
{
  assert(n>0);
  if (!(n&1)) return 2;
  if (prime(n)) return n;

  __int128 x=rand()%(n-2)+2;
  __int128 y=x;
  __int128 c=rand()%10+1;
  __int128 d=1;

  while (d==1) {
    x=(x*x%n+c)%n;
    y=(y*y%n+c)%n;
    y=(y*y%n+c)%n;
    d=GCD(std::abs(x-y), n);
    if (d==n) return pollard_rho(n);
  }
  if (prime(d)) return d;
  else return pollard_rho(d);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);


/** n=p1^e1 * p2^e2 * ... * pk^ek
  * let x=p1^(p1^e1 -1) * p2^(p2^e2 -1) * ... * p{k-1}^(p{k-1}^e{k-1} -1) * pk^(pk^(ek-1) -1) * q^(pk -1) where q is an arbitrary prime number
  * then d(x) = n
  *
  * it is trivial that px^ex-1 >= ex (because px>=2 and ex>=1)
  * therefore, if there exists at least one x such that px^(ex-1)-1 >= ex,
  * the number of possible x is infinite (because we can choose infinitely many distinct q).
  *      if px==2, then ex must be at least 3
  *      if px>=3, then ex must be at least 2
  *  
  */

/** in the case the above condition isn't satisfied:
  * 1) n=p1 * p2 * ... * pk
  *     in this case, x needed to be p1^(p{a1} -1) * p2^(p{a2} -1) * ... * pk^(p{ak} -1) 
  *                 such that a1, a2, ... , ak in {1, 2, ... , k}  and  ai!=aj for i!=j
  *     therefore, the number of possible such x is k!
  *
  * 2) n=2^2 * p1 * p2 * ... * pk
  *     in this case, let z = n/4 = p1 * p2 * ... * pk
  *                   then let x = 2^(z-1) * q * r where q and r are arbitrary prime numbers
  *     therefore, if z-1 >= 2, the number of such x is infinite
  *     in edge case, if n=4, then x must be 8, no other value is possible
  *
  * 3) n=1
  *     in this case, x must be 1, no other value is possible
  */

  // init();
  int t;  std::cin >> t;
  long long int n;
  while (t--) {
    std::cin >> n;

    if (n==1 || n==4) {
      std::cout << "1\n"; 
      continue;
    }
    else if (n%4==0) {
      std::cout << "-1\n";
      continue;
    }

    std::vector<long long int> factors;
    while (n>1) {
      long long int d=pollard_rho(n);
      factors.push_back(d);
      n/=d;
    }
    std::sort(factors.begin(), factors.end());

    bool FLAG=0;
    int k=factors.size();
    for (int i=1;i<k;++i) {
      if (factors[i-1]==factors[i]) {
        FLAG=1;
        break;
      }
    }
    if (FLAG) std::cout << "-1\n";
    else {
      long long int result=1LL;
      for (long long int i=1;i<=k;++i) result*=i;
      std::cout << result << '\n';
    }
  }
  return 0;
}
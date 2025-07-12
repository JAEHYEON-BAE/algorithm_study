// 32242

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

inline long long int mod_mul(long long int a, long long int b, const long long int &MOD)
{
  a%=MOD;b%=MOD;
  return static_cast<long long int>(static_cast<__int128>(a)*static_cast<__int128>(b)%static_cast<__int128>(MOD));
}

long long int mod_exp(long long int a, long long int r, const long long int &MOD)
{
  a%=MOD;
  long long int result=1LL;
  while (r) {
    if (r&1) result=mod_mul(result, a, MOD);
    a=mod_mul(a, a, MOD);
    r>>=1;
  }
  return result;
}

constexpr long long int bases[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller_rabin(long long int n)
{
  if (n==1) return 0;
  else if (n==2 || n==3 || n==5) return 1;
  else if (!(n&1)) return 0;

  long long int u=n-1; int t=0;
  while (!(u&1)) u>>=1, ++t;

  if (n<2047) {
    long long int base=2;
    long long int prev, curr=mod_exp(base, u, n);
    if (curr==1 || curr==n-1) return 1;
    for (int k=0;k<t;++k) {
      prev=curr;
      curr=mod_mul(prev, prev, n);
      if (curr==1 && prev!=1 && prev!=n-1) return 0;
    }
    if (curr!=1) return 0;
    return 1;
  }
  else {
    for (int i=0;i<12;++i) {
      long long int base=bases[i];
      long long int prev, curr=mod_exp(base, u, n);
      if (curr==1 || curr==n-1) continue;
      for (int k=0;k<t;++k) {
        prev=curr;
        curr=mod_mul(prev, prev, n);
        if (curr==1 && prev!=1 && prev!=n-1) return 0;
      }
      if (curr!=1) return 0;
    }
    return 1;
  }
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

  long long int x=rand()%(n-2)+2;
  long long int y=x;
  long long int c=rand()%(n-3)+1;

  auto f=[&n, &c](long long int v) -> long long int {
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

void prime_factorization(long long int n, std::map<long long int, int> &factors)
{
  while (n>1) {
    if (miller_rabin(n)) {
      ++factors[n];
      return;
    }
    long long int d=pollard_rho(n);
    while (n%d==0) {
      ++factors[d];
      n/=d;
    }
  }
}

long long int exp(long long int a, int r)
{
  long long int result=1LL;
  while (r) {
    if (r&1) result=result*a;
    a*=a;
    r>>=1;
  }
  return result;
}

void factor_pairs(int i, long long int d, const std::vector<std::pair<long long int, int>> &f, const long long int &n, std::vector<std::pair<long long int, long long int>> &pairs)
{
  if (d>n/d) return;
  if (i>=f.size()) {
    pairs.push_back({d, n/d});
    return;
  }

  long long int pow=1;
  for (int j=0;j<=f[i].second;++j) {
    factor_pairs(i+1, d*pow, f, n, pairs);
    pow*=f[i].first;
  }
}



int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if (a==0) {
    if (b==0 && c==0) {
      if (d==0) std::cout << "INFINITY";
      else std::cout << '0';
      return 0;
    }
    
    long long int g=GCD(b, c);
    if (d%g) std::cout << '0';
    else std::cout << "INFINITY";
    return 0;
  }


  /* (ax+c)(ay+b)=bc-ad */
  long long int tmp=b*c-a*d;
  if (tmp==0) {
    if (b==0 || c==0 || c%a==0 || b%a==0) std::cout << "INFINITY";
    else std::cout << '0';
    return 0;
  }
  else {
    bool MINUS_FLAG=0;
    if (tmp<0) {
      MINUS_FLAG=1;
      tmp*=-1;
    }
    
    std::map<long long int, int> factors;
    prime_factorization(tmp, factors);

    std::vector<std::pair<long long int, int>> f;
    for (const auto &pair:factors) f.push_back(pair);

    std::vector<std::pair<long long int, long long int>> pairs;
    factor_pairs(0, 1, f, tmp, pairs);

    std::vector<std::pair<long long int, long long int>> result;
    for (const auto &[d1, d2]:pairs) {
      if (MINUS_FLAG) {
        /* ax+c=-d1, ay+b=d2 */
        if ((-d1-c)%a==0 && (d2-b)%a==0) 
          result.push_back({(-d1-c)/a, (d2-b)/a});

        /* ax+c=-d2, ay+b=d1 */
        if ((-d2-c)%a==0 && (d1-b)%a==0) 
          result.push_back({(-d2-c)/a, (d1-b)/a});

        /* ax+c=d1, ay+b=-d2 */
        if ((d1-c)%a==0 && (-d2-b)%a==0) 
          result.push_back({(d1-c)/a, (-d2-b)/a});

        /* ax+c=d2, ay+b=-d1 */
        if ((d2-c)%a==0 && (-d1-b)%a==0) 
          result.push_back({(d2-c)/a, (-d1-b)/a});
      }
      else {
        /* ax+c=d1, ay+b=d2 */
        if ((d1-c)%a==0 && (d2-b)%a==0) 
          result.push_back({(d1-c)/a, (d2-b)/a});
  
        /* ax+c=d2, ay+b=d1 */
        if ((d2-c)%a==0 && (d1-b)%a==0) 
          result.push_back({(d2-c)/a, (d1-b)/a});
        
        /* ax+c=-d1, ay+b=-d2 */
        if ((-d1-c)%a==0 && (-d2-b)%a==0) 
          result.push_back({(-d1-c)/a, (-d2-b)/a});
        
        /* ax+c=-d2, ay+b=-d1 */
        if ((-d2-c)%a==0 && (-d1-b)%a==0) 
          result.push_back({(-d2-c)/a, (-d1-b)/a});
      }
    }

    std::sort(result.begin(), result.end());
    std::cout << result.size() << '\n';
    for (auto &p:result) {
      std::cout << p.first << ' ' << p.second << '\n';
    }
  }

  return 0;
}
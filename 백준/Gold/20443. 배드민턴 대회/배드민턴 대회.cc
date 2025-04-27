// 20443

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static constexpr long long int MOD=1'000'000'007;
static long long int F[101]={};

long long int power(const long long int &a, int r)
{
  if (r==0) return 1;
  if (r==1) return a;
  long long int tmp=power(a, r>>1);
  if (r&1) return tmp*tmp%MOD*a%MOD;
  else return tmp*tmp%MOD;
}

long long int C(const long long int &a, const long long int &b)
{
  if (b==0) return 1;
  // F[a]/(F[b]*F[a-b]);
  long long int tmp=F[b]*F[a-b]%MOD;
  return F[a]*power(tmp, MOD-2)%MOD;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  F[0]=1LL;
  for (int i=1;i<=100;++i) {
    F[i]=F[i-1]*i%MOD;
  }

  long long int n;  std::cin >> n;
  long long int tmp=C(n, n%4);

  n=n>>2<<2;
  long long int pdp=2LL;
  long long int dp=9LL;
  for (int i=5;i<=n;++i) {
    int tmp=dp;
    dp=(i-1)*(pdp+dp)%MOD;
    pdp=tmp;
  }
  std::cout << dp*tmp%MOD;
  
  return 0;
}
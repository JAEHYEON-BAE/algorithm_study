// 2086
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static constexpr long long int MOD=1'000'000'009;

long long int power(int a, int r)
{
  long long int result=1;
  while (r>0) {
    if (r&1) result*=a, result%=MOD;
    a*=a;
    a%=MOD;
    r>>=1;
  }
  return result%MOD;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int n, k;  std::cin >> n >> k;
  std::vector<long long int> dp(7, 0);
  dp[0]=k-1;
  dp[1]=1;

  for (int i=1;i<n;++i) {
    
    std::vector<long long int> tmp(7, 0);
    tmp[0]+=dp[0]*(k-1)%MOD;
    tmp[0]%=MOD;
    for (int j=1;j<7;++j) {
      tmp[0]+=dp[j]*(k-2)%MOD;
      tmp[0]%=MOD;
    }
    tmp[1]=dp[0]+dp[1]+dp[3]+dp[4]+dp[5];
    tmp[1]%=MOD;

    tmp[2]=dp[1]%MOD;
    tmp[3]=dp[2]%MOD;
    tmp[4]=dp[3]%MOD;
    tmp[5]=(dp[2]+dp[6])%MOD;
    tmp[6]=dp[5]%MOD;

    dp=tmp;
  }

  long long int cnt=0LL;
  for (int i=0;i<7;++i) {
    cnt+=dp[i];
    cnt%=MOD;
  }
  std::cout << cnt;
  
  return 0;
}
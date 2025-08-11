// 1750

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

constexpr long long int MOD=10'000'003;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  int max=0;
  std::unordered_map<int, int> freq;
  for (int &x:v) {
    std::cin >> x;
    max=std::max(max, x);
    ++freq[x];
  }

  std::vector<int> mu(max+1, 0);
  mu[1]=1;

  std::vector<int> primes, is_complex(max+1, 0);
  for (int i=2;i<=max;++i) {
    if (!is_complex[i]) {
      primes.push_back(i);
      mu[i]=-1;
    }
    for (const int &p:primes) {
      int tmp=i*p;
      if (tmp>max) break;
      is_complex[tmp]=1;
      if (i%p==0) {mu[tmp]=0;break;}
      else mu[tmp]=-mu[i];
    }
  }

  std::vector<int> cnt(max+1, 0);
  for (int i=1;i<=max;++i) for (int m=i;m<=max;m+=i) {
    cnt[i]+=freq[m];
  }

  long long int res=0;
  for (int i=1;i<=max;++i) {
    res+=((1LL<<cnt[i])%MOD-1LL)*mu[i];
    if (res<0) res+=MOD;
    res%=MOD;
  }
  std::cout << res;
  return 0;
}

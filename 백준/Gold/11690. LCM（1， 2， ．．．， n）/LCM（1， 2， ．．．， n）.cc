// 11690

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

const long long MOD = 1LL<<32;
std::bitset<100'000'001> is_prime;

inline int log_(int x, int base)
{
  return static_cast<int>(log(static_cast<double>(x))/log(static_cast<double>(base)));
}
int power(int x, int k)
{
  if (k==0) return 1;
  if (k==1) return x;
  int tmp=power(x, k>>1);
  if (k&1) return tmp*tmp*x;
  else return tmp*tmp;
}
inline int biggest_power(int x, int n)
{
  return power(x, log_(n, x));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  // std::vector<bool> is_prime(n+1, true);
  is_prime.set();
  is_prime[0]=is_prime[1]=false;

  for (int i=2;i*i<=n;++i) {
    if (is_prime[i]) for (int j=i*i;j<=n;j+=i) {
      is_prime[j]=false;
    }
  }
  long long tot=1;
  for (int i=2;i<=n;++i) {
    if (is_prime[i]) {
      tot=tot*static_cast<long long>(biggest_power(i, n))%MOD;
    }
  }
  std::cout << tot%MOD;
 
  return 0;
}
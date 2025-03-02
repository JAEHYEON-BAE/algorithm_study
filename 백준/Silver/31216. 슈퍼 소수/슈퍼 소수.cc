// 31216

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int MOD=1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<bool> is_prime(318138, true);
  is_prime[0]=is_prime[1]=false;
  for (int i=2;i*i<318138;++i) {
    if (is_prime[i]) for (int j=i*i;j<=318138;j+=i) is_prime[j]=false;
  }
  std::vector<int> primes;
  for (int i=2;i<318138;++i) if (is_prime[i]) primes.push_back(i);
  
  
  int t, n;  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << primes[primes[--n]-1] << '\n';
  }
  
  return 0;
}
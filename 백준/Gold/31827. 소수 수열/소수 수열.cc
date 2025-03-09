// 31827

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::bitset<1'000'001> is_prime;
  is_prime.set();
  is_prime.reset(0), is_prime.reset(1);
  for (int i=2;i*i<=1'000'000;++i) {
    if (is_prime[i]) for (int j=i*i;j<=1'000'000;j+=i) {
      is_prime.reset(j);
    }
  }
  
  int n, k;  std::cin >> n >> k;
  for (int r=1;r<k;++r) {
    std::vector<int> result;
    for (int i=2;i<=1'000'000;++i) {
      if (is_prime[i] && i%k==r) result.push_back(i);
      if (result.size()==n) {
        for (int x:result) std::cout << x << ' ';
        return 0;
      }
    }
  }

  return 0;
}
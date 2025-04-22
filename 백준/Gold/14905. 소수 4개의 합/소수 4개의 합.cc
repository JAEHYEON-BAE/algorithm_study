// 14905

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<bool> is_prime(100'000'001, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<=100'000'000;++i) {
    if (is_prime[i]) for (int j=i<<1;j<=100'000'000;j+=i) {
      is_prime[j]=0;
    }
  }


  int n;
  while (std::cin >> n) {
    if (n<8) {
      std::cout << "Impossible.\n";
      continue;
    }

    if (n&1) {
      std::cout << "2 3 ";
      n-=5;
    }
    else {
      std::cout << "2 2 ";
      n-=4;
    }
    for (int i=2;;++i) {
      if (is_prime[i] && is_prime[n-i]) {
        std::cout << i << ' ' << n-i << '\n';
        break;
      }
    }
  }
  return 0;
}
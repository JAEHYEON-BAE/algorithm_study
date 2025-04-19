// 10210

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  if (k>n/2) {
    std::cout << "NIE"; return 0;
  }
  if (n&1) {
    for (int i=1;i<=n/2;++i) std::cout << i << ' ' << i+n-n/2 << ' ';
    std::cout << n/2+1;
  }
  else {
    for (int i=1;i<=n/2;++i) std::cout << i+n-n/2 << ' ' << i << ' ';
  }

  return 0;
}
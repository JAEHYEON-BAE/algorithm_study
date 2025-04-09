// 13268
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int d=0;
  bool FLAG=0;
  while (n>0) {
    for (int i=1;i<=4;++i) {
      for (int j=0;j<i;++j) {
        n-=5;
        d+=5;
        if (n<=0) {
          d+=n, FLAG=1;
          break;
        }
      }
      if (FLAG) break;
      for (int j=0;j<i;++j) {
        n-=5;
        d-=5;
        if (n<=0) {
          d-=n, FLAG=1;
          break;
        }
      }
      if (FLAG) break;
    }
  }
  std::cout << ((d%5)?d/5+1:d/5);
  
  return 0;
}
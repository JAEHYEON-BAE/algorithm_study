// 3474

#include <iostream>
#include <vector>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    int cnt=0;
    for (int i=5;i<=n;i*=5) {
      cnt+=n/i;
      if (i>INF/5) break;
    }
    std::cout << cnt << '\n';
  }
}
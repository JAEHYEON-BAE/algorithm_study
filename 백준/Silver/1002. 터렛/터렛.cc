// 13545

#include <iostream>
#include <vector>
#include <string>
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

  int t;  std::cin >> t;
  while (t--) {
    int x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (x1==x2 && y1==y2 && r1==r2) {
      std::cout << -1 << '\n';
      continue;
    }
    
    int dist=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    int sum=(r1+r2)*(r1+r2);
    int sub=(r1-r2)*(r1-r2);

    if (dist<sub) std::cout << 0 << '\n';
    else if (dist==sub) std::cout << 1 << '\n';
    else if (sub<dist && dist<sum) std::cout << 2 << '\n';
    else if (dist==sum) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';
  }
  return 0;
}
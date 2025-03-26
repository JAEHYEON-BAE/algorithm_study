// 1491

#include <iostream>
#include <vector>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  int x, y;
  if (n>m) {
    y=m>>1;
    if (m&1) x=n-1-y;
    else x=y-1;
  }
  else {
    x=(n-1)>>1;
    if (n&1) y=m-1-x;
    else y=x+1;
  }
  std::cout << x << ' ' << y;
  return 0;
}
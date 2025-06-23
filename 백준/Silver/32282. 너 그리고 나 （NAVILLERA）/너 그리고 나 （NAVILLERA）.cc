// 32282

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int x, y, c;  std::cin >> x >> y >> c;
  if (x==0 && y==0) {
    std::cout << 0;
    return 0;
  }
  int d=x*x+y*y;
  c*=c;
  if (d<c) {
    std::cout << 2;
    return 0;
  }
  int k2=d/c, k=std::sqrt(k2);

  if (d%c==0 && k*k==k2) std::cout << k;
  else {
    std::cout << k+1;
  }
  return 0;
}

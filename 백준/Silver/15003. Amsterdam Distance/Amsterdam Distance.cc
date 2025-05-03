// 15003

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

static constexpr long double pi = M_PI;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long double m, n, r;  std::cin >> m >> n >> r;
  int ax, ay, bx, by;  std::cin >> ax >> ay >> bx >> by;

  long double tmp=static_cast<long double>(std::abs(bx-ax))*pi/m-2.0L;
  if (tmp<0) {
    std::cout << std::fixed << std::setprecision(15) << static_cast<long double>(std::abs(bx-ax))/m*(r*std::min(ay, by)/n)*pi + r*std::abs(by-ay)/n;
  }
  else {
    std::cout << std::fixed << std::setprecision(15) << static_cast<long double>(ay+by)*r/n;
  }
  return 0;
}
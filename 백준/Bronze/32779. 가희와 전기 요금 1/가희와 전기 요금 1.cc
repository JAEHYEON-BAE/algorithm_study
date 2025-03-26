// 32779

#include <iostream>
#include <vector>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int q;  std::cin >> q;
  while (q--) {
    long double a, m;  std::cin >> a >> m;
    long double tmp=a*m*0.00176L;
    std::cout << static_cast<long long int>(tmp) << '\n';
  }
  return 0;
}
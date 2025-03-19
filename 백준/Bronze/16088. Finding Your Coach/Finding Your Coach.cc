// 16088

#include <iostream>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int l, r, n, m;  std::cin >> l >> r >> n >> m;
    if (n==m) std::cout << 'G' << '\n';
    else {
      int gap=abs(n-m);
      if (gap<=l && gap<=r) std::cout << 'E' << '\n';
      else if (gap<=l) std::cout << 'L' << '\n';
      else std::cout << 'R' << '\n';
    }
  }
  
  return 0;
}
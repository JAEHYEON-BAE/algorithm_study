// 16884

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::cout << (n&1?"koosaga\n":"cubelover\n");
  }
  return 0;
}


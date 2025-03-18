// 3745

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  while (std::cin >> n) {
    int x;
    std::vector<int> LIS;
    for (int i=0;i<n;++i) {
      std::cin >> x;
      if (LIS.empty() || LIS.back()<x) LIS.push_back(x);
      else {
        *std::lower_bound(LIS.begin(), LIS.end(), x) = x;
      }
    }
    std::cout << LIS.size() << '\n';
  }

  
  return 0;
}
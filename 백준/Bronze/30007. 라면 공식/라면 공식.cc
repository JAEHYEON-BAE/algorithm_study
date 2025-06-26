// 30007

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  for (int i=0;i<n;++i) {
    int a, b, x;  std::cin >> a >> b >> x;
    std::cout << a*(x-1)+b << '\n';
  }
  return 0;
}

// 1057

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, a, b;  std::cin >> n >> a >> b;
  if (a>b) std::swap(a, b);
  int r=1;
  while (n--) {
    if (abs(a-b)==1 && (a&1)) {
      std::cout << r;
      return 0;
    }
    a=(a+1)>>1;
    b=(b+1)>>1;
    ++r;
  }

  return 0;
}
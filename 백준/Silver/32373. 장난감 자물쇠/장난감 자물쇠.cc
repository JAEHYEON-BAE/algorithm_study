// 12660

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  for (int i=0;i<n;++i) {
    int x; std::cin >> x;
    if ((x-i)%k!=0) {
      std::cout << "No";
      return 0;
    }
  }
  std::cout << "Yes";
  return 0;
}
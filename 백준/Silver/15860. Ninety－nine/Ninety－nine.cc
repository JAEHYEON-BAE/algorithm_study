// 15680

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int x=0;
  bool b=0;
  while (1) {
    if (x%3) std::cout << (x=((x/3)+1)*3) << std::endl;
    else std::cout << (x=x+(b?1:2)) << std::endl;

    if (x==99) return 0;

    b^=1;
    std::cin >> x;
    if (x==99) return 0;
  }
  return 0;
}
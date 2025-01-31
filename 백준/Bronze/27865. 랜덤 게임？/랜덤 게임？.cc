
#include <iostream>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n; std::cin >> n;

  char c;
  while (true) {
    std::cout << "? 1\n";
    std::cout << std::flush;
    std::cin >> c;
    if (c=='Y') {
      std::cout << "! 1"; std::cout << std::flush; return 0;}
  }

  return 0; 
}

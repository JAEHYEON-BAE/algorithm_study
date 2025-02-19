#include <iostream>
#include <iomanip>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
    
  long double a, b;
  std::cin >> a >> b;
  std::cout << std::fixed << std::setprecision(15) << a/b;
  return 0;
}
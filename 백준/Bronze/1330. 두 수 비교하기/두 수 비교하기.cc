// 1330

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  if (n==m) std::cout << "==";
  else std::cout << ((n>m)?'>':'<');

  return 0;
}
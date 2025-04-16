// 25333
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int GCD(int x, int y)
{
  while (y) {
    int tmp=y;
    y=x%y;
    x=tmp;
  }
  return x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int a, b, x;  std::cin >> a >> b >> x;
    std::cout << x/GCD(a, b) << '\n';
  }
  
  return 0;
}
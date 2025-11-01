// 18398

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    for (int i=0;i<n;++i) {
      int a, b;  std::cin >> a >> b;
      std::cout << a+b << ' ' << a*b << '\n';
    }
  }
  return 0;
}
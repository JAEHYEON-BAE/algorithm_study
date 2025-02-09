// 1112

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  if (n<8) {std::cout << -1; return 0;}
  
  std::vector<bool> is_prime(n, true);
  for (int i=2;i*i<n;++i) {
    if (is_prime[i]) {
      for (int j=2;i*j<n;++j) is_prime[i*j]=false;
    }
  }
  /** Goldbach's conjection
    *   since n-4 is even number, it can be divided into 
    *   two prime numbers
    */

  if (n%2) {
    std::cout << "2 3 ";
    n-=5;
    if (n<4) {std::cout << -1; return 0;}
    for (int i=2;i<=n/2;++i) {
      if (is_prime[i] && is_prime[n-i]) {
        std::cout << i << ' ' << n-i;
        return 0;
      }
    }
  } else {
    std::cout << "2 2 ";
    n-=4;
    for (int i=2;i<=n/2;++i) {
      if (is_prime[i] && is_prime[n-i]) {
        std::cout << i << ' ' << n-i;
        return 0;
      }
    }
  }
  
  return 0; 
}
// 14905

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

bool is_prime(int n) 
{
  for (int i=2;i*i<=n;++i) {
    if (n%i==0) return 0;
  }
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // std::vector<bool> is_prime(100'000'001, 1);
  // is_prime[0]=is_prime[1]=0;
  // for (int i=2;i*i<=100'000'000;++i) {
  //   if (is_prime[i]) for (int j=i<<1;j<=100'000'000;j+=i) {
  //     is_prime[j]=0;
  //   }
  // }

  int n;
  while (std::cin >> n) {
    if (n<8) {
      std::cout << "Impossible.\n";
      continue;
    }

    if (n&1) {
      std::cout << "2 3 ";
      n-=5;
    }
    else {
      std::cout << "2 2 ";
      n-=4;
    }
    for (int i=2;;++i) {
      if (is_prime(i) && is_prime(n-i)) {
        std::cout << i << ' ' << n-i << '\n';
        break;
      }
    }
  }
  return 0;
}
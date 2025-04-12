// 3087
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int n, k;  std::cin >> n >> k;
  if (n<=k) {std::cout << ((n<<1)-1); return 0;}
  std::cout << (n*n-1)/k+k;
  return 0;
}
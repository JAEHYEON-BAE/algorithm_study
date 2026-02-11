// 21490

#include <iostream>
#include <vector>
#include <string>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int GCD(int a, int b)
{
  while (b) {
    int t=a%b;
    a=b;
    b=t;
  }
  return a;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k; std::cin >> n >> k;
  int g=GCD(n, k);
  std::cout << (n-n/g);
  return 0;
}

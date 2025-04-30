// 2942

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int GCD(int a, int b)
{
  while (b>0) {
    int tmp=b;
    b=a%b;
    a=tmp;
  }
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int r, g;  std::cin >> r >> g;

  int gcd=GCD(r, g);
  for (int i=1;i*i<=gcd;++i) {
    if (i*i==gcd) {
      std::cout << i << ' ' << r/i << ' ' << g/i << '\n';
    }
    else if (gcd%i==0) {
      std::cout << i << ' ' << r/i << ' ' << g/i << '\n';
      std::cout << gcd/i << ' ' << r/(gcd/i) << ' ' << g/(gcd/i) << '\n';
    }
  }
  
  return 0;
}
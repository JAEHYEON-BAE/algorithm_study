// 17177

#include <iostream>
#include <vector>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c;  std::cin >> a >> b >> c;

  int p=a, q=(b*c)<<1, r=a*(b*b+c*c-a*a);
  int d=q*q-((p*r)<<2);
  if (d<0) {std::cout << -1; return 0;}
  int x=(std::sqrt(d)-q)/(p<<1);
  if (x<0) {std::cout << -1; return 0;}
  std::cout << x;
  
  
  return 0;
}
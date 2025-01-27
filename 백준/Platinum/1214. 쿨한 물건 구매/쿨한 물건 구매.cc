// 1214

#include <iostream>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int d, p, q;  std::cin >> d >> p >> q;

  if (p==1 || q==1) {std::cout << d; return 0;}

  if (p<q) std::swap(p, q);
  int min=(~0u)>>1;
  for (int i=0;i<=std::min(d/p, q);++i) {
    min=std::min(min, (q-(d-p*i)%q)%q);
  }
  min=std::min(min, (p-d%p)%p);
  std::cout << d+min;

  return 0; 
}

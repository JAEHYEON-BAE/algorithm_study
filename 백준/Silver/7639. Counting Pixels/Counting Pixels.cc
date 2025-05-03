// 7639

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int x, y, r;
  while (std::cin >> x >> y >> r) {
    if (x==0 && y==0 && r==0) return 0;
    long long int tmp=0;
    for (long long int i=0;i<r;++i) {
      long long int j=std::sqrt(r*r-i*i);
      tmp+=j+1;
      if (j*j+i*i==r*r) --tmp;      
    }
    std::cout << (tmp<<2) << '\n';
  }
  
  return 0;
}
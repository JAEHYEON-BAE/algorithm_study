// 13860

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int sum[7]={
0, 26, 1378, 54106, 1882010, 61288890, 1914783546
};
static constexpr int power26[7]={
1, 26, 676, 17576, 456976, 11881376, 308915776
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int r;
  for (int i=6;i>=0;--i) {
    if (n>=sum[i]) {
      r=i; break;
    }
  }
  n-=sum[r];
  int a=n/(r+1);
  int b=n%(r+1);

  while (1) {
    if (b--==0) {
      std::cout << static_cast<char>('A'+(a/power26[r]));
      return 0;
    }
    a%=power26[r];
    --r;
  }
  
  return 0;
}
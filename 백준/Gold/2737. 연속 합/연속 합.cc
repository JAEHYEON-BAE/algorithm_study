// 2737

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    while (!(n&1)) n>>=1;

    int res=1;
    for (int i=3;i*i<=n;i+=2) {
      int tmp=1;
      while (n%i==0) {n/=i;++tmp;}
      res*=tmp;
    }
    if (n!=1) res<<=1;
    std::cout << res-1 << '\n';
  }

  return 0;
}

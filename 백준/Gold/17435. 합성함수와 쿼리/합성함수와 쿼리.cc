// 17435

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int m;  std::cin >> m;
  std::vector<int> f(m);
  std::vector<std::vector<int>> sparse(20, std::vector<int>(m));

  for (int i=0;i<m;++i) {
    std::cin >> f[i];
    --f[i];
    sparse[0][i]=f[i];
  }

  for (int i=1;i<20;++i) for (int j=0;j<m;++j) {
    sparse[i][j]=sparse[i-1][sparse[i-1][j]];
  }
  
  int q;  std::cin >> q;
  while (q--) {
    int n, x;  std::cin >> n >> x;
    --x;
    while (n>0) {
      int _n=(31-__builtin_clz(n));
      x=sparse[_n][x];
      n-=1<<_n;
    }
    std::cout << x+1 << '\n';
  }
  
  return 0;
}
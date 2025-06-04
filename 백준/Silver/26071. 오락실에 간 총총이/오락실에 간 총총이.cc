// 26071

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

inline int cnt(const std::vector<std::vector<bool>> &map)
{
  int tmp=0;
  for (const auto &v:map) for (const bool &b:v) if (b) ++tmp;
  return tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int l=n, r=-1, u=n, d=-1;
  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<n;++j) if (line[j]=='G') {
      l=std::min(l, j);
      r=std::max(r, j);
      u=std::min(u, i);
      d=std::max(d, i);
    }
  }

  if (l==r) {
    if (u==d) {std::cout << 0; return 0;}
    else {std::cout << std::min(n-1-u, d); return 0;}
  }
  else if (u==d) {
    std::cout << std::min(n-1-l, r); return 0;
  }
  else {
    std::cout << std::min(n-1-l, r)+std::min(n-1-u, d);
  }
  
  return 0;
}
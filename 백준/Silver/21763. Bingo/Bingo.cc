// 21763

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  if (n*(n-1)<k) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";

  std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, 1));
  for (int i=0;i<n;++i) grid[i][i]=0;

  int tmp=n*(n-1)-k;
  for (int i=0;i<n*n;++i) {
    if (tmp==0) break;
    
    if (grid[i/n][i%n]) {
      grid[i/n][i%n]=0;
      --tmp;
    }
  }

  for (const auto &x:grid) {
    for (const bool &b:x) {
      if (b) std::cout << '#';
      else std::cout << '.';
    }
    std::cout << '\n';
  }
  
  
  return 0;
}
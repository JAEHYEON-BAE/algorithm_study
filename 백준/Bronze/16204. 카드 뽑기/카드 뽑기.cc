// 16204

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  int r=std::max(m, k)-std::min(m, k);
  std::cout << n-r;
  
  return 0;
}
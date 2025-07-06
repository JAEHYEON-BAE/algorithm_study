#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, result=0;
  for (int i=0;i<5;++i) {
    std::cin >> n;
    result+=n*n;
    result%=10;
  }
  std::cout << result;

  return 0;
}
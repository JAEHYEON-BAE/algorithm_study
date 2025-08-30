// 17598

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;
  int l=0, t=0;
  while (std::cin >> s) {
    if (s=="Lion") ++l;
    else ++t;
  }
  std::cout << (l>t?"Lion":"Tiger");
  
  return 0;
}
// 25166

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int s, m;  std::cin >> s >> m;
  if (s<1024) std::cout << "No thanks";
  else {
    s-=1023;
    if ((m&s)==s) std::cout << "Thanks";
    else std::cout << "Impossible";
  }
  
  return 0;
}
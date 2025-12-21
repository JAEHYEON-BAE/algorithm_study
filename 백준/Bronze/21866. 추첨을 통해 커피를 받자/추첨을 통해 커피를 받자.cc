// 21866 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x; int tot=0;
  for (int i=0;i<9;++i) {
    std::cin >> x;
    if (i<2 && x>100) {std::cout << "hacker"; return 0;}
    else if (i<4 && x>200) {std::cout << "hacker"; return 0;}
    else if (i<6 && x>300) {std::cout << "hacker"; return 0;}
    else if (i<8 && x>400) {std::cout << "hacker"; return 0;}
    else if (x>500) {std::cout << "hacker"; return 0;}
    tot+=x;
  }

  std::cout << (tot<100?"none":"draw");
  return 0;
}

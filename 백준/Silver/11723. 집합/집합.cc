// 19686

#include <iostream>
#include <vector>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  /* bitmasking */
  u_int32_t bit=0;
  u_int32_t max=-1;
  
  int n;  std::cin >> n;
  std::string cmd; 
  int x;
  
  while (n--) {
    std::cin >> cmd;
    if (cmd=="add") {
      std::cin >> x;
      bit |= (1<<x);
    } else if (cmd=="remove") {
      std::cin >> x;
      bit &= max-(1<<x);
    } else if (cmd=="check") {
      std::cin >> x;
      std::cout << ((bit<<(31-x)>>31)&1) << '\n';
    } else if (cmd=="toggle") {
      std::cin >> x;
      bit ^= (1<<x);
    } else if (cmd=="all") {
      bit = max;
    } else if (cmd=="empty") {
      bit = 0;
    } else {
      assert(1);
    }
  }

  return 0; 
}

// 10868

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int l;  std::cin >> l;
  std::vector<std::string> str(l, "");
  char op, a;  int x;
  int i=-1;
  while (l--) {
    std::cin >> op;
    if (op=='T') {
      ++i;
      std::cin >> a;
      if (i==0) str[0].push_back(a);
      else str[i]=str[i-1], str[i].push_back(a);
    }
    else {
      std::cin >> x;
      if (op=='U') {
        ++i;
        str[i]=str[i-x-1];
      }
      else if (op=='P') {
        std::cout << str[i][x] << '\n';
      }
    } 
  }
 
  return 0; 
}

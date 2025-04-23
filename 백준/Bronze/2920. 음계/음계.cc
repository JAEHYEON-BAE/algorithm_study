// 2920

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  bool asc=1, desc=1;
  int i=7, x, pre;
  std::cin >> pre;
  while (i--) {
    std::cin >> x;
    if (x!=pre+1) asc=0;
    if (x!=pre-1) desc=0;

    if (!asc && !desc) {
      std::cout << "mixed";
      return 0;
    }
    pre=x;
  }

  std::cout << (asc?"ascending":"descending");

  return 0;
}
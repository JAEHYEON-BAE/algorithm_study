// 1587

#include <iostream>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  /** Basically, nA/2 + nB/2
    *   new line -> good or bad?
    */
  int nA, nB, m;  std::cin >> nA >> nB >> m; 
  if (nA%2==0 || nB%2==0) {
    std::cout << nA/2 + nB/2;
    return 0;
  }
  int a, b;  
  while (m--) {
    std::cin >> a >> b;
    if (a%2==1 && b%2==1) {
      std::cout << nA/2+nB/2+1;
      return 0;
    }
  }
  std::cout << nA/2 + nB/2;
 
  return 0; 
}

// 10775

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int G, P;  std::cin >> G >> P;

  std::vector<int> offset(G);
  std::vector<bool> used(G, false);
  for (int i=0;i<G;++i) offset[i]=i-1;
  int x;
  int result=0;
  for (int i=0;i<P;++i) {
    std::cin >> x;
    --x;
    if (used[x] && offset[x]==-1) {
      std::cout << result;
      return 0;
    }
    else {
      if (used[x]) {
        int k=offset[x];
        while (k>=0) {
          if (!used[k]) break;
          k=offset[k];
        }
        offset[x]=k;
        if (k==-1) {
          std::cout << result; return 0;
        }
        used[k]=true;
      } else {
        used[x]=true;
        int k=offset[x];
        while (k>=0) {
          if (!used[k]) break;
          k=offset[k];
        }
        offset[x]=k;
      }
    }
    ++result;
  }

  std::cout << result;  
  return 0; 
}

// 18114

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, c;  std::cin >> n >> c;
  std::vector<int> w(n);
  for (int i=0;i<n;++i) {
    std::cin >> w[i];
    if (w[i]==c) {
      std::cout << 1;
      return 0;
    }
  }

  std::sort(w.begin(), w.end());
  if (w[0]>c) {
    std::cout << 0;
    return 0;
  }

  // choose 2
  int l=0, r=n-1;
  while (l<r) {
    int tmp=w[l]+w[r];
    if (tmp==c) {
      std::cout << 1;
      return 0;
    }
    else if (tmp<c) ++l;
    else if (tmp>c) --r;
  }

  // choose 3
  for (int i=0;i<n-2;++i) {
    if (w[i]+w[i+1]+w[i+2]>c) {
      std::cout << 0;
      return 0;
    }
    l=i+1, r=n-1;
    while (l<r) {
      int tmp=w[l]+w[r];
      if (tmp==c-w[i]) {
        std::cout << 1;
        return 0;
      }
      else if (tmp<c) ++l;
      else if (tmp>c) --r;
    }
  }
  std::cout << 0; 
  return 0;
}
// 2128

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, d, k;  std::cin >> n >> d >> k;
  std::vector<std::vector<int>> know(n);
  for (int i=0;i<n;++i) {
    int num;  std::cin >> num;
    int x;
    while (num--) {
      std::cin >> x;
      know[i].push_back(--x);
    }
  }
  std::vector<bool> comb(d, false);
  std::fill(comb.begin(), comb.begin()+k, true);

  int max=-1;
  do {
    int tmp=n;
    for (int i=0;i<n;++i) for (int p:know[i]) {
      if (!comb[p]) {
        --tmp;
        break;
      }
    }
    max=std::max(max, tmp);
  } while (std::prev_permutation(comb.begin(), comb.end()));

  std::cout << max;
  return 0;
}
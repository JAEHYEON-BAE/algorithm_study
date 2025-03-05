// 16495

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int cnt[100'001]{};
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    ++cnt[x];
  }
  int count=0;
  for (int i=0;i<100'001;++i) {
    count+=cnt[i];
    if (count>=((n+1)>>1)) {
      std::cout << i;
      return 0;
    }
  }
  return 0;
}
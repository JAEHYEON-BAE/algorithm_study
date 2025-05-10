// 32713

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<int> v(n);
  std::unordered_set<int> set;
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    set.insert(v[i]);
  }

  int max=0;

  for (const int &x:set) {
    int l=0, r=0;
    int tmp=0;
    int cnt=0, del=0;
    for (;r<n;++r) {
      if (v[r]==x) ++cnt;
      else if (++del>k) {
        while (del>k) {
          if (v[l]==x) --cnt;
          else --del;
          ++l;
        }
      }
      tmp=std::max(tmp, cnt);
    }
    max=std::max(max, tmp);
  }
  std::cout << max;
  return 0;
}
// 21049

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

struct Stack
{
  int idx, h;
  Stack(int idx, int h): idx(idx), h(h) {}
  bool operator <(const Stack& other) const {
    if (h==other.h) return idx<other.idx;
    return h<other.h;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i=0;i<n;++i) {
    std::cin >> v[i].first;
    v[i].second=i+1;
  }
  std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());

  std::vector<std::pair<int, int>> result;
  while (v[1].first) {
    result.push_back({v[0].second, v[1].second});
    --v[0].first; --v[1].first;
    std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
  }

  if (v[0].first) std::cout << "no";
  else {std::cout << "yes\n";
        for (auto &x:result) std::cout << x.first << ' ' << x.second << '\n';
       }

  return 0;
}
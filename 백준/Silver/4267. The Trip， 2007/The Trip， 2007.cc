// 4267

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  while (std::cin >> n) {
    if (!n) break;
    std::map<int, int> cnt;
    int k=0;
    for (int i=0;i<n;++i) {
      int x;
      std::cin >> x;
      if (cnt.find(x)==cnt.end()) cnt[x]=0;
      ++cnt[x];
      k=std::max(k, cnt[x]);
    }

    std::vector<std::vector<int>> result(k);
    int idx=0;
    for (const auto &p:cnt) {
      for (int i=0;i<p.second;++i)
        result[(idx+i)%k].push_back(p.first);
      idx=(idx+p.second)%k;
    }

    std::cout << k << '\n';
    for (const auto &v:result) {
      for (int i=0;i<v.size()-1;++i) std::cout << v[i] << ' ';
      std::cout << v.back() << '\n';
    }
  }

  return 0;
}
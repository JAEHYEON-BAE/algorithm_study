// 14012

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; long long int m;  std::cin >> n >> m;

  std::vector<std::pair<int, int>> ch;

  std::vector<int> a(n), b(n);
  for (int i=0;i<n;++i) std::cin >> a[i];
  for (int i=0;i<n;++i) {
    std::cin >> b[i];
    if (b[i]>a[i]) ch.push_back({a[i], b[i]});
  }


  std::sort(ch.begin(), ch.end(), 
    [] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
      return a.first<b.first;
    });

  for (const auto &x:ch) {
    if (x.first>m) break;
    m+=x.second-x.first;
  }
  std::cout << m;
  return 0;
}
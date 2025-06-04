// 26071

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

template <typename T>
inline void print_v(const std::vector<std::vector<T>> &v)
{
  for (auto x:v) {
    for (auto y:x) std::cout << y << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
  return;
}
template <typename T, size_t N>
inline void print_v(const T (&v)[N][N])
{
  for (int i=0;i<N;++i) {
    for (int j=0;j<N;++j) std::cout << v[i][j] << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
}

inline int cnt(const std::vector<std::vector<bool>> &map)
{
  int tmp=0;
  for (const auto &v:map) for (const bool &b:v) if (b) ++tmp;
  return tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  std::vector<int> used(n+1, 0);
  int sum=0;
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    sum+=v[i];
    ++used[v[i]];
  }
  int max=0;
  for (int i=1;i<=n;++i) {
    if (used[i]) max=std::max(max, i*used[i]);
  }
  sum+=max;
  std::sort(v.begin(), v.end());
  std::cout << sum << '\n';
  for (int &x:v) std::cout << x << ' ';
  
  return 0;
}
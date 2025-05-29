// 14567

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <queue>

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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::unordered_set<int>> map(n);
  std::vector<int> degree(n, 0);
  for (int i=0;i<m;++i) {
    int a, b;  std::cin >> a >> b;
    --a;--b;
    map[a].insert(b);
    ++degree[b];
  }

  std::vector<int> result(n, -1);
  std::unordered_set<int> done;
  int term=1;
  while (done.size()<n) {
    std::vector<int> tmp=degree;
    
    for (int i=0;i<n;++i) if (degree[i]==0 && done.find(i)==done.end()) {
      result[i]=term;
      done.insert(i);
      for (const int &next:map[i]) --tmp[next];
    }
    ++term;
    degree=tmp;
  }
  for (int i=0;i<n;++i) std::cout << result[i] << ' ';
  return 0;
}
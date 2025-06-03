// 2568

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


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::pair<int, int>> lines(n);
  for (int i=0;i<n;++i) {
    std::cin >> lines[i].first >> lines[i].second;
  }
  std::sort(lines.begin(), lines.end());

  std::vector<int> LIS, backtrace;
  for (int i=0;i<n;++i) {
    int x=lines[i].second;
    if (LIS.empty() || LIS.back()<x) {
      backtrace.push_back(LIS.size());
      LIS.push_back(x);
    }
    else {
      auto pos=std::lower_bound(LIS.begin(), LIS.end(), x);
      backtrace.push_back(pos-LIS.begin());
      *pos=x;
    }
  }
  std::cout << n-LIS.size() << '\n';

  std::unordered_set<int> answer;
  int tmp=LIS.size()-1;
  for (int i=n-1;i>=0;--i) {
    if (tmp==backtrace[i]) {
      answer.insert(lines[i].second);
      --tmp;
    }
  }

  for (int i=0;i<n;++i) {
    if (answer.find(lines[i].second)==answer.end()) {
      std::cout << lines[i].first << '\n';
    }
  }
  
  return 0;
}
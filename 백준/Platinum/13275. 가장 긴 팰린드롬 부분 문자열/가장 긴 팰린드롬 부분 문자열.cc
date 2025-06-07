// 17141

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
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

long long int manacher(const std::string &s)
{
  int n=s.size();
  std::vector<int> p(n, 0);
  int mid=0, r=0;
  int max=0;

  for (int i=0;i<n;++i) {
    int mirror=(mid<<1)-i;

    if (i<r) p[i]=std::min(r-i, p[mirror]);

    while (i-p[i]-1>=0 && i+p[i]+1<n && s[i-p[i]-1]==s[i+p[i]+1]) {
      ++p[i];
    }

    if (i+p[i]>r) {
      mid=i;
      r=i+p[i];
    }

    max=std::max(max, p[i]);
  }
  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string line, str="#";  std::cin >> line;
  for (const char &c:line) str+=c, str+='#';
  std::cout << manacher(str);
  
  return 0;
}
// 1014

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

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

inline bool condition_1(int x)
{
  return (x&(x>>1))==0;
}
inline bool condition_2(int prev, int curr)
{
  return (prev&(curr>>1))==0 && (prev&(curr<<1))==0;
}
inline int stobi(const std::string &s)
{
  int res=0;
  for (int i=0;i<s.size();++i) {
    if (s[i]=='.') res|=1<<i;
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int c;  std::cin >> c;
  while (c--) {
    int n, m;  std::cin >> n >> m;
    std::vector<std::vector<int>> dp(n, std::vector<int>(1<<m, 0));

    std::string line;  std::cin >> line;
    int bline=stobi(line);
    for (int j=0;j<(1<<m);++j) {
      if ((bline|j)==bline && condition_1(j)) dp[0][j]=__builtin_popcount(j);
    }
    
    for (int i=1;i<n;++i) {
      std::string line;  std::cin >> line;
      int bline=stobi(line);

      for (int prev=0;prev<(1<<m);++prev) {
        if (dp[i-1][prev]!=0) for (int curr=0;curr<(1<<m);++curr) {
          if ((bline|curr)==bline && condition_1(curr) && condition_2(prev, curr)) dp[i][curr]=std::max(dp[i][curr], dp[i-1][prev]+__builtin_popcount(curr));
        }
      }
    }
    std::cout << *std::max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
  }
  return 0;
}
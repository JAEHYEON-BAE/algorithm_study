// 24555

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <array>


#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
// static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

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


static constexpr int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int solve(int x, std::vector<int> &dp)
{
  // if (x<15430) return dp[x];
  if (x==0) return INF;
  if (dp[x]!=-1) return dp[x];

  int &res=dp[x];
  res=INF;
  for (int i=1;i<=x/2;++i) {
    res=std::min(res, solve(i, dp)+solve(x-i, dp));
  }

  for (int p=2;p*p<=x;++p) {
    if (x%p==0) res=std::min(res, solve(p, dp)+solve(x/p, dp));
  }

  for (int i=1;power10[i]<=x && i<10;++i) {
    if (x/power10[i-1]%10==0) continue;
    
    res=std::min(res, solve(x/power10[i], dp)+solve(x%power10[i], dp));
  }
  // std::cout << x << ' ' << res << '\n';
  return res;  
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<int> dp(n+1, -1);
  
  dp[0]=INF;
  dp[1]=1;
  std::cout << solve(n, dp);
  
  return 0;
}
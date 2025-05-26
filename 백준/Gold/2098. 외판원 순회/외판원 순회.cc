// 2098

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

int TSP(int visited, int curr, std::vector<std::vector<int>> &dp, const std::vector<std::vector<int>> &v)
{
  int n=v.size();
  if (visited==(1<<n)-1) return v[curr][0];

  int &tmp=dp[visited][curr];

  if (tmp!=-1) return tmp;

  tmp=INF;
  for (int next=0;next<n;++next) {
    if ((visited&(1<<next)) || v[curr][next]==INF) continue;
    tmp=std::min(tmp, v[curr][next]+TSP(visited|(1<<next), next, dp, v));
  }
  return tmp;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    std::cin >> v[i][j];
    if (v[i][j]==0) v[i][j]=INF;
  }

  std::vector<std::vector<int>> dp(1<<n, std::vector<int>(n, -1));
  std::cout << TSP(1, 0, dp, v);
  
  return 0;
}
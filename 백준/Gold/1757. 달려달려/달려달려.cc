// 1757

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

constexpr int nINF=1<<31;

class _1757
{
  const int &n, &m;
  const std::vector<int> &d;
  /* dp[i][j]: i분째에, 지침지수가 j인 경우 달린 거리의 최댓값 */
  std::vector<std::vector<int>> dp;

public:
  _1757(const int &n, const int &m, const std::vector<int> &d): n(n), m(m), d(d) {
    dp.assign(n+1, std::vector<int>(m+1, nINF));
  }

  int solve(int i, int j) {
    int &tmp=dp[i][j];
    if (tmp!=nINF) return tmp;

    if (i==n) {
      if (j==0) return tmp=0;
      else return tmp=nINF;
    }
    
    if (j+1<=m) tmp=std::max(tmp, solve(i+1, j+1)+d[i]);
    if (j && i+j<=n) tmp=std::max(tmp, solve(i+j, 0));
    if (j==0) tmp=std::max(tmp, solve(i+1, 0));
    return tmp;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> d(n);
  for (int i=0;i<n;++i) std::cin >> d[i];

  _1757 x(n, m, d);
  std::cout << x.solve(0, 0);
  return 0;
}
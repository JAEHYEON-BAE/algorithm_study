// 15724

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> p(n, std::vector<int>(m, 0));
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    std::cin >> p[i][j];
    if (i==0 && j==0) dp[0][0]=p[0][0];
    else if (i==0) dp[0][j]=dp[0][j-1]+p[0][j];
    else if (j==0) dp[i][0]=dp[i-1][0]+p[i][0];
    else dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1] + p[i][j];
  }
  
  
  int k;  std::cin >> k;
  while (k--) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    --x1, --x2, --y1, --y2;
    int tmp=dp[x2][y2];

    if (x1) tmp-=dp[x1-1][y2];
    if (y1) tmp-=dp[x2][y1-1];
    if (x1 && y1) tmp+=dp[x1-1][y1-1];
    std::cout << tmp << '\n';
  }
  
  return 0;
}
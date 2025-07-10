// 22983

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  std::vector<std::vector<bool>> board(n, std::vector<bool>(3000, 0));
  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<m;++j) if (line[j]=='B') board[i][j]=1;
  }

  std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(m, 1LL));
  long long int result=n*m;

  for (int i=1;i<n;++i) for (int j=1;j<m;++j) {
    if (!(board[i][j]^board[i-1][j-1]) && board[i][j]^board[i-1][j] && board[i][j]^board[i][j-1]) {
      long long int cnt=std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]));
      result+=cnt;
      dp[i][j]=cnt+1;
    }
  }
  std::cout << result;
  
  
  return 0;
}
// 5569

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory.h>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

#define EAST 0
#define NORTH 1

constexpr int MOD=100'000;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int w, h;  std::cin >> w >> h;
  int dp[102][102][2][2];
  memset(dp, 0, sizeof(dp));

  dp[2][1][NORTH][1]=1;
  dp[1][2][EAST][1]=1;

  for (int r=1;r<=w;++r) for (int c=1;c<=h;++c) {
    dp[r][c+1][EAST][1]+=dp[r][c][EAST][0]+dp[r][c][EAST][1];
    dp[r][c+1][EAST][1]%=MOD;
    dp[r+1][c][NORTH][0]+=dp[r][c][EAST][1];
    dp[r+1][c][NORTH][0]%=MOD;

    dp[r+1][c][NORTH][1]+=dp[r][c][NORTH][0]+dp[r][c][NORTH][1];
    dp[r+1][c][NORTH][1]%=MOD;
    dp[r][c+1][EAST][0]+=dp[r][c][NORTH][1];
    dp[r][c+1][EAST][0]%=MOD;
  }

  int res=0;
  for (int i=0;i<2;++i) for (int j=0;j<2;++j) res+=dp[w][h][i][j];
  std::cout << res%MOD;
  
  return 0;
}
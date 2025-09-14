// 34338

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s, n;  std::cin >> s >> n;
  int ls=s.size(), ln=n.size();
  if (ls<ln) {
    std::cout << "-1";
    return 0;
  }

  // cost[i][j][k] := S의 i번째 문자까지 사용해서 N의 j-1번째 문자까지 만든 후, j번째 문자를 k로 만드는 최소비용
  std::vector<std::vector<std::vector<int>>> cost(1+ls, std::vector<std::vector<int>>(1+ln, std::vector<int>(10, 1001)));
  cost[0][0][0]=0;
  for (int i=1;i<=ls;++i) {
    int x=s[i-1]-'0';
    for (int k=0;k<10;++k) if (cost[i-1][0][k]<1001) {
      int y=(k+x)%10;
      cost[i][0][y]=std::min(cost[i][0][y], cost[i-1][0][k]);
      cost[i][0][k]=std::min(cost[i][0][k], 1+cost[i-1][0][k]);
    }
  }

  // dp[i][j] := S의 i번째 문자까지 사용해서 N의 j번째 문자까지 만드는 최소비용
  std::vector<std::vector<int>> dp(1+ls, std::vector<int>(1+ln, 1001));
  dp[0][0]=0;

  for (int i=1;i<=ls;++i) {
    int x=s[i-1]-'0';
    for (int j=1;j<=ln;++j) {
      if (dp[i-1][j-1]<1001) {
        cost[i][j][x]=std::min(cost[i][j][x], dp[i-1][j-1]);
        cost[i][j][0]=std::min(cost[i][j][0], 1+dp[i-1][j-1]);
      }
      for (int k=0;k<10;++k) if (cost[i-1][j][k]<1001) {
        int y=(k+x)%10;
        cost[i][j][y]=std::min(cost[i][j][y], cost[i-1][j][k]);
        cost[i][j][k]=std::min(cost[i][j][k], 1+cost[i-1][j][k]);
      }
      int target=n[j-1]-'0';
      dp[i][j]=cost[i][j][target];
    }
  }

  std::cout << (dp[ls][ln]<1001?dp[ls][ln]:-1);
  return 0;
}
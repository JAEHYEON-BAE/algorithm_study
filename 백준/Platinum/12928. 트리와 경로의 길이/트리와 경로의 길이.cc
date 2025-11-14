// 12928

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

  int n, s;  std::cin >> n >> s;

  int min=std::max(n-2, 0);
  int max=(n-2)*(n-1)/2;
  if (s<min || s>max) {std::cout << '0'; return 0;}
  else if (s==max || s==max) {std::cout << '1'; return 0;}
  
  std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(max+1, std::vector<int>(n, 0)));
  std::vector<std::vector<bool>> valid(n+1, std::vector<bool>(max+1, 0));

  dp[1][0][0]=1;
  valid[1][0]=1;
  
  dp[2][0][1]=2;
  valid[2][0]=1;
  
  dp[3][1][1]=2;
  dp[3][1][2]=1;
  valid[3][1]=1;

  for (int i=3;i<n;++i) for (int j=i-2;j<=(i-2)*(i-1)/2;++j) if (valid[i][j]) {
    for (int k=1;k<i;++k) if (dp[i][j][k] && !valid[i+1][j+k]) {
      dp[i+1][j+k]=dp[i][j];
      dp[i+1][j+k][k]-=1;
      dp[i+1][j+k][k+1]+=1;
      dp[i+1][j+k][1]+=1;
      
      valid[i+1][j+k]=1;
    }
  }

  std::cout << valid[n][s];
  
  
  return 0;
}
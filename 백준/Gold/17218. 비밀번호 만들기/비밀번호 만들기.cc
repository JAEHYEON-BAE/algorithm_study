// 17218

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s1, s2;  std::cin >> s1 >> s2;
  int n1=static_cast<int>(s1.size()), n2=static_cast<int>(s2.size());
  std::vector<std::vector<int>> dp(1+n1, std::vector<int>(1+n2, 0));
  dp[0][0]=0;

  for (int i=0;i<n1;++i) for (int j=0;j<n2;++j) {
    if (s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j]+1;
    else dp[i+1][j+1]=std::max(dp[i+1][j], dp[i][j+1]);
  }

  std::string LCS="";
  for (int i=n1-1, j=n2-1;i>=0&&j>=0;) {
    if (s1[i]==s2[j]) {
      LCS.push_back(s1[i]);
      --i; --j;
    }
    else {
      if (i==0) --j;
      else if (j==0) --i;
      else {
        if (dp[i][j+1]>dp[i+1][j]) --i;
        else --j;
      }
    }
  }
  std::reverse(LCS.begin(), LCS.end());
  std::cout << LCS;

  return 0;
}
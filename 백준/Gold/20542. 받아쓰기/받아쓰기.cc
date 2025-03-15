// 20542

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
  std::string str, ans;  std::cin >> str >> ans;

  std::vector<std::vector<int>> score(n+1, std::vector<int>(m+1, 0));
  for (int i=1;i<=n;++i) score[i][0]=i;
  for (int i=1;i<=m;++i) score[0][i]=i;
  
  for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) {
    if 
      (str[i-1]==ans[j-1] ||
      (str[i-1]=='i' && (ans[j-1]=='j' || ans[j-1]=='l')) ||
      (str[i-1]=='v' && ans[j-1]=='w')) {
      score[i][j]=score[i-1][j-1];
    }
    else {
      score[i][j]=1 + std::min(
        score[i-1][j-1], 
        std::min(score[i-1][j], score[i][j-1])
      );
    }
  }
  std::cout << score[n][m];
 
  return 0;
}
// 1509

#include <stdio.h>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl
#define min(a, b) (a<b)?a:b;

const int INF=1'000'000'007;

bool is_palin(const char *str, const int n) {
  auto l=str, r=str+n;
  while (l<r) {
    if (*l!=*r) return false;
    ++l, --r;
  }
  return true;  
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  char str[2501];
  scanf("%s", str);
  int dp[2501];
  for (auto i=dp;i<dp+2501;++i) *i=INF;
  dp[0]=1;
  for (int i=1;i<2501;++i) {
    if (str[i]=='\0') {printf("%d", dp[i-1]);return 0;}
    if (is_palin(str, i)) dp[i]=1;
    else {
      for (int j=1;j<i;++j) {
        if (is_palin(str+j, i-j)) {
          dp[i]=min(dp[i], dp[j-1]+1);
        }
      }
      dp[i]=min(dp[i], dp[i-1]+1);
    }
  }
  return 0; 
}

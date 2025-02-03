// 1509

#include <stdio.h>

#define min(a, b) (a<b)?a:b;

const int INF=1000000007;

int is_palin(char *str, const int n) {
  char* l=str;
  char* r=str+n;
  while (l<r) {
    if (*l!=*r) return 0;
    ++l, --r;
  }
  return 1;  
}

int main() {

  char str[2501];
  scanf("%s", str);
  int dp[2501];
  for (int* i=dp;i<dp+2501;++i) *i=INF;
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

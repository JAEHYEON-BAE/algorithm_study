// 15486

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/* DEFINE FASTIO */
namespace fastio
{
  /* INPUT */
  #define INPUT_BUFFER_SIZE (1<<20)
  
  char get()
  {
    static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
    if (S==T) {
      T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
      if (S==T) return EOF;
    }
    return *S++;
  }
  void read(int &x)
  {
    static char c; x=0;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
    if (MINUS_FLAG) x*=-1;
  }
}
/* END FASTIO */

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; fastio::read(n);
  
  std::vector<int> dp(n+2, 0);
  
  int t, p;
  for (int i=1;i<=n;++i) {
    fastio::read(t), fastio::read(p);
    dp[i]=std::max(dp[i], dp[i-1]);
    if (i+t<=n+1) dp[i+t]=std::max(dp[i+t], dp[i]+p);
  }
  dp[n+1]=std::max(dp[n+1], dp[n]);
  
  std::cout << dp[n+1];
  return 0;
}

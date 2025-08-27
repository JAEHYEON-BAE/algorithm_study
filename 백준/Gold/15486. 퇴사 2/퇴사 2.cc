// 15486

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

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
  
  std::vector<int> t(n), p(n);
  for (int i=0;i<n;++i) {
    fastio::read(t[i]), fastio::read(p[i]);
  }

  std::vector<int> dp(n+1, 0);
  for (int i=n-1;i>=0;--i) {
    if (i+t[i]>n) dp[i]=dp[i+1];
    else dp[i]=std::max(dp[i+1], dp[i+t[i]]+p[i]);
  }
  std::cout << dp[0];
  
  return 0;
}

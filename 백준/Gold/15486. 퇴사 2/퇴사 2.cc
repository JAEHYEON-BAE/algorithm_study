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

class _15486
{
  const int &n;
  const std::vector<int> &times, &pay;
  std::vector<int> dp;

  int DP(int i) {
    if (i==n) return 0;
    else if (dp[i]!=-1) return dp[i];
    else if (times[i]==1) return dp[i]=DP(i+1)+pay[i];
    else if (i+times[i]>n) {
      if (i+1<n) return dp[i]=DP(i+1);
      else return dp[i]=0;
    }  
    else return dp[i]=std::max(DP(i+1), DP(i+times[i])+pay[i]);
  }

public:
  _15486(const int &n, const std::vector<int> &times, const std::vector<int> &pay): n(n), times(times), pay(pay) {
    dp.assign(n, -1);
  }

  int result() {
    return DP(0);
  }
};

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
  _15486 x(n, t, p);
  std::cout << x.result();
  
  return 0;
}


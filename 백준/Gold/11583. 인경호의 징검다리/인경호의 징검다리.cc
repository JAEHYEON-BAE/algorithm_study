// 11583

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
constexpr int INF=(~0u)>>2;

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
  
int factors(int x, int d)
{
  int cnt=0;
  while (x%d==0) ++cnt, x/=d;
  return cnt;
}

int solve(int n, int k, const std::vector<int> &v, int d)
{
  std::vector<int> dp(k, INF);
  dp[0]=factors(v[0], d);

  for (int i=1;i<n;++i) {
    int a=factors(v[i], d);

    std::vector<int> tmp(k, INF);
    for (int j=0;j<k;++j) {
      tmp[0]=std::min(tmp[0], dp[j]+a);

      if (j+1<k) tmp[j+1]=std::min(tmp[j+1], dp[j]);
    }
    dp=tmp;
  }
  return dp[0];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  read(t);
  while (t--) {
    int n, k; read(n), read(k);
    
    std::vector<int> v(n);
    for (int &x:v) read(x);
    
    std::cout << std::min(solve(n, k, v, 2), solve(n, k, v, 5)) << '\n';
  }
  return 0;
}


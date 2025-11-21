// 33582

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

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

void build(int u, int p, std::vector<int> &dp, std::vector<std::vector<int>> &f, const std::vector<int> &a, const std::vector<std::vector<int>> &G)
{
  dp[u]=a[u];

  for (const int &v:G[u]) if (v!=p) {
    build(v, u, dp, f, a, G);

    dp[u]=std::max(dp[u], 1+dp[v]);
    if (1+dp[v]>=f[u][0]) {
      f[u][1]=f[u][0];
      f[u][0]=1+dp[v];
    }
    else if (1+dp[v]>=f[u][1]) f[u][1]=1+dp[v];
  }
  return;
}

void DFS(int u, int p, int d, std::vector<int> &dp, std::vector<std::vector<int>> &f, const std::vector<int> &a, const std::vector<std::vector<int>> &G) 
{
  if (d>=f[u][0]) {
    f[u][1]=f[u][0];
    f[u][0]=d;
  }
  else if (d>=f[u][1]) f[u][1]=d;

  dp[u]=std::max(dp[u], d);
  for (const int &v:G[u]) if (v!=p) {
    int tmp=(f[u][0]==1+dp[v])?f[u][1]:f[u][0];
    DFS(v, u, std::max(1+a[u], 1+tmp), dp, f, a, G);
  }
  return;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<std::vector<int>> G(n);
  for (int i=0;i<n-1;++i) {
    int u, v;  read(u), read(v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  std::vector<int> a(n);
  for (int &x:a) read(x);

  std::vector<int> dp(n, 0);
  std::vector<std::vector<int>> f(n, std::vector<int>(2, 0));
  build(0, -1, dp, f, a, G);
  DFS(0, -1, 0, dp, f, a, G);

  int min=(~0u)>>1;
  for (int i=0;i<n;++i) min=std::min(min, dp[i]);

  std::cout << min;
  return 0;
}
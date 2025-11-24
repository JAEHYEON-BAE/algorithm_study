// 22856

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

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

int DFS(int u, std::vector<int> &cnt, const std::vector<std::vector<int>> &G)
{
  for (const int &v:G[u]) if (v!=-1) {
    cnt[u]+=1+DFS(v, cnt, G);
  }
  return cnt[u];
}

int solve(int u, const std::vector<int> &cnt, const std::vector<std::vector<int>> &G)
{
  int res=
      ((G[u][0]!=-1)
      ? 2*(1+cnt[G[u][0]])
      : 0)
  +   ((G[u][1]!=-1)
      ?1+solve(G[u][1], cnt, G)
      : 0);
  // std::cout << u << ' ' << res << '\n';
  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  int a, b, c;
  std::vector<std::vector<int>> G(n+1, std::vector<int>(2, -1));
  std::vector<int> cnt(n+1, 0);

  int res=0;
  for (int _=0;_<n;++_) {
    read(a), read(b), read(c);
    G[a][0]=b, G[a][1]=c;
  }
  
  DFS(1, cnt, G);
  std::cout << solve(1, cnt, G);
  return 0;
}
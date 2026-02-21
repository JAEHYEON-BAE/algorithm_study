// 31414

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
template<typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

std::vector<int> v;

struct SCC
{
  int n;
  const std::vector<int> &G;
  int id=0;
  std::vector<int> stk;
  std::vector<int> idx;
  std::vector<bool> done;

  int res;

  SCC(int n, const std::vector<int> &G): n(n), G(G), idx(n, -1), done(n, 0), res(n) 
  {
    for (int i=0;i<n;++i) if (idx[i]==-1) DFS(i);
  }

  int DFS(int u)
  {
    idx[u]=id++;
    stk.push_back(u);
    int lowlink=idx[u];
    int v=G[u];
    if (idx[v]==-1) {
      lowlink=std::min(lowlink, DFS(v));
    }
    else if (!done[v]) {
      lowlink=std::min(lowlink, idx[v]);
    }

    if (lowlink==idx[u]) {
      int l=0;
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        done[top]=1;
        ++l;
        if (top==u) break;
      }
      if (l>1 && (l==2 || l&1)) --res;
    }
    return lowlink;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<int> v(n);
  for (int &x:v) read(x), --x;

  SCC scc(n, v);
  std::cout << scc.res;

  return 0;
}

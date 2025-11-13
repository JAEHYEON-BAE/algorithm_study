// 4196

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
template <typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

struct SCC
{
  int n;
  const std::vector<std::vector<int>> &G;
  std::vector<int> index, stk, scc;
  std::vector<bool> done;
  int id=0, scc_id=0;

  SCC(int n, const std::vector<std::vector<int>> &G): n(n), G(G) {
    index.assign(n, -1);
    scc.assign(n, -1);
    done.assign(n, 0);

    for (int i=0;i<n;++i) if (index[i]==-1) DFS(i);
  }

  int DFS(int u) {
    index[u]=id++;
    stk.push_back(u);
    int lowlink=index[u];
    for (const int &v:G[u]) {
      if (index[v]==-1) lowlink=std::min(lowlink, DFS(v));
      else if (!done[v]) lowlink=std::min(lowlink, index[v]);
    }
    if (lowlink==index[u]) {
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        scc[top]=scc_id;
        done[top]=1;
        if (top==u) break;
      }
      ++scc_id;
    }
    return lowlink;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  read(t);
  while (t--) {
    int n, m;  read(n), read(m);
    std::vector<std::vector<int>> G(n);
    while (m--) {
      int x, y;  read(x), read(y);
      --x, --y;
      G[x].push_back(y);
    }

    SCC s(n, G);
    int cnt=s.scc_id;
    std::vector<bool> in_degree(s.scc_id, 0);
    for (int u=0;u<n;++u) for (const int &v:G[u]) {
      int a=s.scc[u];
      int b=s.scc[v];
      if (a!=b && !in_degree[b]) in_degree[b]=1, --cnt;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
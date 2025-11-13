// 25808

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
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
    done.assign(n, 0);
    scc.assign(n, -1);

    for (int i=0;i<n;++i) if (index[i]==-1) DFS(i);
  }

private:
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
        done[top]=1;
        scc[top]=scc_id;
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

  int c, b;  read(c), read(b);

  std::vector<std::vector<int>> G(c);
  for (int i=0;i<b;++i) {
    // bot[i] is listening to channed l
    int l, m;  read(l), read(m);
    --l;
    for (int j=0;j<m;++j) {
      int a;  read(a);  --a;
      G[l].push_back(a);
    }
  }

  SCC x(c, G);
  int scc_cnt=x.scc_id;
  std::vector<int> cnts(scc_cnt, 0);
  for (int i=0;i<c;++i) ++cnts[x.scc[i]];

  std::vector<int> in_degree(scc_cnt, 0);
  for (int u=0;u<c;++u) for (const int &v:G[u]) {
    int a=x.scc[u];
    int b=x.scc[v];
    if (a!=b) ++in_degree[b];
  }

  int cand=-1;
  for (int i=0;i<scc_cnt;++i) {
    if (in_degree[i]==0) {
      if (cand!=-1) {std::cout << '0'; return 0;}
      else cand=i;
    }
  }

  std::vector<bool> visited(scc_cnt, 0);
  std::cout << (cand!=-1?cnts[cand]:0);
  return 0;
}
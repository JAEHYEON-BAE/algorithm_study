// 6543

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

/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

char obuf[OUTPUT_BUFFER_SIZE];
int opos=0;
inline void flush() 
{
  fwrite(obuf, 1, opos, stdout);
  opos=0;
}
inline void put(char c)
{
  if (opos==OUTPUT_BUFFER_SIZE) flush();
  obuf[opos++]=c;
}
void write(int x)
{
  if (x==0) return put('0');
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

struct SCC
{
  int n;  
  const std::vector<std::vector<int>> &G;
  std::vector<int> index, done, scc;
  int id=0, scc_id=0;
  std::vector<int> stk;
  std::vector<std::vector<int>> scc_group;

public:
  SCC(int n, const std::vector<std::vector<int>> &G): n(n), G(G) {
    index.assign(n, -1);
    done.assign(n, 0);
    scc.assign(n, -1);

    for (int i=0;i<n;++i) if (index[i]==-1) DFS(i);
  }

private:
  int DFS(int u) {
    index[u]=id++;
    int lowlink=index[u];
    stk.push_back(u);
    for (const int &v:G[u]) {
      if (index[v]==-1) lowlink=std::min(lowlink, DFS(v));
      else if (!done[v]) lowlink=std::min(lowlink, index[v]);
    }

    if (lowlink==index[u]) {
      std::vector<int> group;
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        scc[top]=scc_id;
        group.push_back(top);
        done[top]=1;
        if (top==u) break;
      }
      scc_group.push_back(group);
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

  int n, m; 
  while (1) {
    read(n);
    if (!n) break;
    read(m);
    std::vector<std::vector<int>> G(n);
    for (int i=0;i<m;++i) {
      int v, w;  read(v), read(w);
      --v, --w;
      G[v].push_back(w);
    }
    SCC x(n, G);
    std::vector<int> out_degree(x.scc_id, 0);
    for (int u=0;u<n;++u) for (const int &v:G[u]) {
      int a=x.scc[u];
      int b=x.scc[v];
      if (a!=b) ++out_degree[a];
    }

    std::vector<int> ans;
    for (int i=0;i<n;++i) if (out_degree[x.scc[i]]==0) write(i+1), put(' ');
    put('\n');
  }
  flush();
  return 0;
}
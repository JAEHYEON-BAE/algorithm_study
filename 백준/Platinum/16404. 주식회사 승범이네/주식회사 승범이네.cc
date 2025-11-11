// 16404

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


void DFS(int u, std::vector<int> &tin, std::vector<int> &tout, const std::vector<std::vector<int>> &G)
{
  static int time=0;
  tin[u]=++time;
  for (const int &v:G[u]) DFS(v, tin, tout, G);
  tout[u]=time;
}

struct Fenwick
{
  int n;
  std::vector<int> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void add(int i, int d) {
    for (;i<=n;i+=i&-i) tree[i]+=d; 
  }
  void add(int l, int r, int d) {
    add(l, d);
    add(r+1, -d);
  }
  int sum(int i) const {
    int res=0;
    for (;i>0;i-=i&-i) res+=tree[i];
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  read(n), read(m);
  std::vector<std::vector<int>> G(n+1);
  for (int i=1;i<=n;++i) {
    int p;  read(p);
    if (p!=-1) G[p].push_back(i);
  }

  std::vector<int> tin(n+1, -1), tout(n+1, -1);
  DFS(1, tin, tout, G);

  Fenwick fw(n);
  int q, i, w;
  while (m--) {
    read(q);
    if (q==1) {
      read(i), read(w);
      fw.add(tin[i], tout[i], w);
    }
    else if (q==2) {
      read(i);
      write(fw.sum(tin[i]));
      put('\n');
    }
    else assert(!"INVALID INPUT");
  }
  flush();
  return 0;
}
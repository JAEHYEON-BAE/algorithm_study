// 18227

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

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
template <typename T>
void write(T x)
{
  if (x==0) return put('0');
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

void DFS(int u, std::vector<int> &s, std::vector<int> &e, std::vector<int> &d, const std::vector<std::vector<int>> &G)
{
  static int t=0;
  s[u]=++t;
  for (const int &v:G[u]) if (s[v]==-1) {
    d[v]=1+d[u];
    DFS(v, s, e, d, G);
  }
  e[u]=t;
}

struct Fenwick
{
  int n;  
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0ll) {}

  void update(int i) {
    for (;i<=n;i+=i&-i) ++tree[i];
  }

  ll query(int i) const {
    ll res=0ll;
    for (;i>0;i-=i&-i) res+=tree[i];
    return res;
  }

  ll query(int l, int r) const {
    return query(r)-query(l-1);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, c;  read(n), read(c);
  std::vector<std::vector<int>> G(n+1);
  for (int i=0;i<n-1;++i) {
    int x, y;  read(x), read(y);
    G[x].push_back(y);
    G[y].push_back(x);
  }

  std::vector<int> s(n+1, -1), e(n+1, -1), d(n+1, 1);
  DFS(c, s, e, d, G);

  Fenwick fw(n);

  int q;  read(q);
  while (q--) {
    int cmd, a;  read(cmd), read(a);
    if (cmd==1) fw.update(s[a]);
    else write(fw.query(s[a], e[a])*d[a]), put('\n');
  }
  flush();
  return 0;
}
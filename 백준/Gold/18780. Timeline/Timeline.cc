// 18780 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

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
template<typename T>
void read(T &x)
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
template<typename T>
void write(T x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

struct Edge
{
  int to, cost;
  Edge() {}
  Edge(int t, int c): to(t), cost(c) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, c;  read(n), read(m), read(c);
  std::vector<int> s(n), in_degree(n, 0);
  std::vector<std::vector<Edge>> G(n);
  for (int &x:s) read(x);
  for (int i=0;i<c;++i) {
    int a, b, x;  read(a), read(b), read(x);
    --a, --b;
    G[a].push_back(Edge(b, x));
    ++in_degree[b];
  }
  std::queue<int> q;
  std::vector<int> res(n, -1);
  for (int i=0;i<n;++i) {
    res[i]=std::max(res[i], s[i]);
    if (in_degree[i]==0) q.push(i);
  }

  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const auto &[v, x]:G[u]) {
      res[v]=std::max(res[v], x+res[u]);
      if (--in_degree[v]==0) q.push(v);
    }
  }
  for (const int &x:res) write(x), put('\n');

  flush();
  return 0;
}

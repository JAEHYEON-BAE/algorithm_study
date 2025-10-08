// 34224

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

struct Edge
{
  int to, weight;
  Edge() {}
  Edge(int t, int w): to(t), weight(w) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<std::vector<Edge>> G(n);
  for (int _=0;_<n-1;++_) {
    int u, v, w;  read(u), read(v), read(w);
    --u;--v;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }

  std::queue<int> q;
  std::vector<int> dist(n, -1);

  q.push(0);
  dist[0]=0;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const auto &[v, w]:G[u]) if (dist[v]==-1) {
      dist[v]=dist[u]^w;
      q.push(v);
    }
  }


  long long int res=0LL;
  std::sort(dist.begin(), dist.end());
  int prev=0;
  long long int cnt=0;
  for (const int &d:dist) {
    if (d==prev) ++cnt;
    else {
      res+=cnt*(cnt-1)/2;
      prev=d;
      cnt=1;
    }
  }
  res+=cnt*(cnt-1)/2;

  std::cout << res;
  return 0;
}
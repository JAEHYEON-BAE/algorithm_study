// 13161

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

static constexpr int INF=(~0u)>>1;

struct Edge
{
  int to, rev, cap;
  Edge() {}
  Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
};
struct MaxFlow
{
  int n;
  std::vector<std::vector<Edge>> G;
  std::vector<int> level, iter;

private:
  void BFS(int s) {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> q;
    q.push(s);
    level[s]=0;
    while (!q.empty()) {
      int u=q.front();
      q.pop();
      for (const Edge &e:G[u]) if (e.cap && level[e.to]==-1) {
        level[e.to]=1+level[u];
        q.push(e.to);
      }
    }
  }

  int DFS(int u, int t, int flow) {
    if (u==t) return flow;
    for (int &it=iter[u];it<G[u].size();++it) {
      Edge &e=G[u][it];
      if (e.cap && level[e.to]==1+level[u]) {
        int f=DFS(e.to, t, std::min(flow, e.cap));
        if (f) {
          e.cap-=f;
          G[e.to][e.rev].cap+=f;
          return f;
        }
      }
    }
    return 0;
  }

public:
  MaxFlow(int n): n(n), G(n), level(n), iter(n) {}

  void add_edge(int u, int v, int cap) {
    Edge a(v, G[v].size(), cap);
    Edge b(u, G[u].size(), 0);

    G[u].push_back(a);
    G[v].push_back(b);
  }

  int max_flow(int s, int t, std::vector<int> &left, std::vector<int> &right) {
    int flow=0;
    while (1) {
      BFS(s);
      if (level[t]==-1) break;
      std::fill(iter.begin(), iter.end(), 0);
      while (int addf=DFS(s, t, INF)) flow+=addf;
    }

    for (int i=1;i<n-1;++i) {
      if (level[i]==-1) left.push_back(i-1);
      else right.push_back(i-1);
    }
    
    return flow;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  MaxFlow mf(n+2);
  for (int i=1;i<=n;++i) {
    int x;  read(x);
    if (x==0) mf.add_edge(0, i, 0), mf.add_edge(i, n+1, 0);
    else if (x==1) mf.add_edge(0, i, 0), mf.add_edge(i, n+1, INF);
    else if (x==2) mf.add_edge(0, i, INF), mf.add_edge(i, n+1, 0);
  }

  std::vector<std::vector<int>> w(n, std::vector<int>(n));
  for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) {
    int x;  read(x);
    if (x) {
      mf.add_edge(i, j, x);
      mf.add_edge(j, i, x);
    }
  }

  std::vector<int> left, right;
  std::cout << mf.max_flow(0, n+1, left, right)/2 << '\n';
  for (int &x:left) std::cout << x+1 << ' ';
  std::cout << '\n';
  for (int &x:right) std::cout << x+1 << ' ';
  std::cout << '\n';
  return 0;
}
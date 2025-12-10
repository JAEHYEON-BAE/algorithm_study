// 18118 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

constexpr int INF=(~0u)>>1;

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
  int to, cost;
  Edge() {};
  Edge(int t, int c): to(t), cost(c) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  read(n), read(m);
  std::vector<std::vector<Edge>> G(n);
  for (int i=0;i<m;++i) {
    int a, b, c;  read(a), read(b), read(c);
    --a, --b;
    G[a].push_back(Edge(b, c));
    G[b].push_back(Edge(a, c));
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq_e, pq_o;
  std::vector<int> d_e(n, INF), d_o(n, INF);
  int s=0, e=n-1;
  pq_e.push({0, s});
  d_e[s]=0;
  while (!pq_e.empty() || !pq_o.empty()) {
    int d, u;
    if (!pq_e.empty() && !pq_o.empty()) {
      if (pq_e.top()<pq_o.top()) {
        d=pq_e.top().first, u=pq_e.top().second;
        pq_e.pop();
      }
      else {
        d=pq_o.top().first, u=pq_o.top().second;
        pq_o.pop();
      }
    }
    else {
      if (!pq_e.empty()) {
        d=pq_e.top().first, u=pq_e.top().second;
        pq_e.pop();
      }
      else {
        d=pq_o.top().first, u=pq_o.top().second;
        pq_o.pop();
      }
    }
    for (const auto &[v, cost]:G[u]) {
      int nd=cost+d;
      if (nd&1 && d_o[v]>nd) {
        d_o[v]=nd;
        pq_o.push({nd, v});
      }
      else if (!(nd&1) && d_e[v]>nd) {
        d_e[v]=nd;
        pq_e.push({nd, v});
      }
    }
  }
  std::cout << (d_o[n-1]<INF?d_o[n-1]:0);
  
  return 0;
}

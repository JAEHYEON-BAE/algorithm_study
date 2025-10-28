// 28120

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
constexpr int INF=(~0u)>>1;

struct Student
{
  int idx, score;
  Student() {}
  Student(int i, int s): idx(i), score(s) {}

  bool operator<(const Student &o) const {
    return score>o.score;
  }
};

struct Edge
{
  int to, rev, cap;
  Edge() {}
  Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
};

class MF
{
  int n;
  std::vector<std::vector<Edge>> G, backup;
  std::vector<int> level, iter;
  int students, groups;

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
  int DFS(int v, int t, int flow) {
    if (v==t) return flow;
    for (int &it=iter[v];it<G[v].size();++it) {
      Edge &e=G[v][it];
      if (e.cap && level[e.to]==1+level[v]) {
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
  MF(int _n, int _k): students(_n), groups(_k), n(_n+_k+2), G(n), level(n), iter(n, 0) {}

  void add_edge(int u, int v, int cap) {
    Edge a(v, G[v].size(), cap);
    Edge b(u, G[u].size(), 0);

    G[u].push_back(a);
    G[v].push_back(b);
  }

  void capture() {
    backup=G;
  }
  void recover() {
    G=backup;
  }

  int max_flow() {
    int flow=0;
    while (1) {
      BFS(0);
      if (level[n-1]==-1) break;
      std::fill(iter.begin(), iter.end(), 0);
      while (int f=DFS(0, n-1, INF)) flow+=f;
    }
    return flow;
  }

  void result(std::vector<std::vector<int>> &res) const {
    
    for (const Edge &re:G[n-1]) if (re.cap) {
      for (const Edge &ree:G[re.to]) if (ree.to!=n-1 && ree.cap) {
        res[re.to-(students+1)].push_back(ree.to);
      }
    }
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k, x;  std::cin >> n >> k >> x;

  // SOURCE: 0, SINK: n+k+1
  MF mf(n, k);
  for (int i=1;i<=n;++i) mf.add_edge(0, i, 1);
  for (int i=n+1;i<=n+k;++i) mf.add_edge(i, n+k+1, x);
  
  std::vector<std::vector<int>> a(n);
  for (int i=0;i<n;++i) {
    int c;  std::cin >> c;
    a[i].resize(c);
    for (int &j:a[i]) std::cin >> j, --j;
  }
  std::vector<Student> students(n);
  for (int i=0;i<n;++i) {
    students[i].idx=i;
    std::cin >> students[i].score;
  }
  std::sort(students.begin(), students.end());

  
  int flow=0;
  for (const Student &s:students) {
    mf.capture();
    for (const int &group:a[s.idx]) {
      mf.add_edge(1+s.idx, n+1+group, 1);
    }
    int addf=mf.max_flow();
    if (addf) flow+=addf;
    else mf.recover();
  }
  // std::cout << flow << '\n';

  std::vector<std::vector<int>> res(k);
  mf.result(res);
  for (const auto &v:res) {
    std::cout << v.size() << ' ';
    for (const int &s:v) std::cout << s << ' ';
    std::cout << '\n';
  }
  
  return 0;
}
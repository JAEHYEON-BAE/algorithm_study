// 11266

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>

namespace fastio
{
  #define INPUT_BUFFER_SIZE 100'000
  
  /* INPUT */
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
  void read(long long int &x)
  {
    static char c; x=0;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
    if (MINUS_FLAG) x*=-1;
  }
}

#endif
class _11266
{
  const int &v;
  const std::vector<std::vector<int>> &graph;
  std::vector<bool> visited;
  std::vector<bool> is_cut;
  std::vector<int> dfs_num, low_link;

  int id=0;
  void DFS(int u, int p) {
    if (dfs_num[u]==-1) dfs_num[u]=id++;
    visited[u]=1;
    low_link[u]=dfs_num[u];

    for (const int &v:graph[u]) if (v!=p) {
      if (!visited[v]) {
        DFS(v, u);
        low_link[u]=std::min(low_link[u], low_link[v]);

        if (p!=-1 && low_link[v]>=dfs_num[u]) is_cut[u]=1;
      }

      else low_link[u]=std::min(low_link[u], dfs_num[v]);
    }
    
    if (p==-1 && graph[u].size()>1) {
      int tmp=low_link[graph[u][0]];
      for (const int &child:graph[u]) {
        if (low_link[child]!=tmp) {is_cut[u]=1; break;}
      }
    }

    return;
  }

public:
  _11266(const int &v, const std::vector<std::vector<int>> &graph): v(v), graph(graph) {
    visited.assign(v, 0);
    is_cut.assign(v, 0);
    dfs_num.assign(v, -1);
    low_link.assign(v, 100'01);
  }

  void solve() {
    for (int i=0;i<v;++i) if (dfs_num[i]==-1) DFS(i, -1);

    std::vector<int> cut;
    for (int i=0;i<v;++i) if (is_cut[i]) cut.push_back(i);

    std::cout << cut.size() << '\n';
    for (int &x:cut) std::cout << x+1 << ' ';
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int v, e, a, b;  read(v), read(e);
  std::vector<std::vector<int>> graph(v);
  for (int i=0;i<e;++i) {
    read(a), read(b);
    --a;--b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  _11266 x(v, graph);
  x.solve();
  
  return 0;
}
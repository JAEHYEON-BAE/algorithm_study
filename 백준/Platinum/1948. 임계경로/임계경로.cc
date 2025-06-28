// 1948

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>
#include <cmath>
#include <type_traits>

namespace fastio
{
  #define INPUT_BUFFER_SIZE 100'000
  #define OUTPUT_BUFFER_SIZE 1'000'000
  
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
  void read(std::string &s, int size=0)
  {
    static char c; s="";
    if (size) s.reserve(size);
    for (c=get();c<'!';c=get());
    for (;c>='!';c=get()) s+=c;
  }
  void read(long double &ld) 
  {
    static char c; ld=0.0L;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) ld=ld*10+(c-'0');
    if (c=='.') {
      long double t=1.0L;
      for (c=get();c>='0'&&c<='9';c=get()) {
        t/=10;
        ld+=t*(c-'0');
      }
    }
    if (MINUS_FLAG) ld*=-1.0L;
  }
  void readline(std::string &s, int size=0)
  {
    static char c; s="";
    if (size) s.reserve(size);
    for (c=get();c!='\n'&&c!=EOF;c=get()) s+=c;
  }
}

#endif

class _1948
{
  const int &n;
  const std::vector<std::unordered_map<int, int>> &graph;
  const std::vector<std::unordered_map<int, int>> &rgraph;
  std::vector<int> &in_degree;
  std::vector<int> topo;

public:
  _1948(const int &n, const std::vector<std::unordered_map<int, int>> &graph, const std::vector<std::unordered_map<int, int>> &rgraph, std::vector<int> &in_degree): n(n), graph(graph), rgraph(rgraph), in_degree(in_degree) {}

  void topological_ordering(std::vector<int> &dp, std::vector<int> &prev) {
    std::queue<int> q;
    for (int i=0;i<n;++i) if (!in_degree[i]) q.push(i);

    while (!q.empty()) {
      int curr=q.front();
      q.pop();
      for (const auto &[next, w]:graph[curr]) {
        if (dp[next]<dp[curr]+w) {
          dp[next]=dp[curr]+w;
          prev[next]=curr;
        }
        if (!--in_degree[next]) q.push(next);
      }
    }
  }

  int count(const int &e, const std::vector<int> &dp) {
    std::vector<std::vector<bool>> visited_e(n, std::vector<bool>(n, 0));
    std::vector<bool> visited_v(n, 0);
    int cnt=0;
    
    std::queue<int> q;
    q.push(e);

    while (!q.empty()) {
      int curr=q.front();
      q.pop();
      for (const auto &[prev, w]:rgraph[curr]) {
        if (dp[curr]==dp[prev]+w && !visited_e[prev][curr]) {
          ++cnt;
          visited_e[prev][curr]=1;

          if (!visited_v[prev]) {
            visited_v[prev]=1;
            q.push(prev);
          }
        }
      }
    }
    return cnt;
  }

  void solve(int s, int e) {
    
    std::vector<int> dp(n, -1);
    std::vector<int> prev(n, -1);
    dp[s]=0;

    // Topological Ordering + Longest Path
    topological_ordering(dp, prev);

    std::cout << dp[e] << '\n' << count(e, dp);
  }

};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int n, m;  read(n), read(m);

  std::vector<std::unordered_map<int, int>> graph(n), rgraph(n);
  std::vector<int> in_degree(n, 0);
  for (int i=0;i<m;++i) {
    int u, v, w;
    read(u), read(v), read(w);
    --u;--v;
    graph[u][v]=w;
    rgraph[v][u]=w;
    ++in_degree[v];
  }
  int s, e;  read(s), read(e);
  --s;--e;

  _1948 x(n, graph, rgraph, in_degree);
  x.solve(s, e);
  
  return 0;
}
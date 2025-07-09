// 30869

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  
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

constexpr int INF=(~0u)>>2;

struct Bus
{
  int e, t, g;
  Bus(){}
  Bus(int e, int t, int g): e(e), t(t), g(g) {}
};


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n, m, k;  read(n), read(m), read(k);

  std::vector<std::vector<Bus>> graph(n);

  for (int i=0;i<m;++i) {
    int s, e, t, g;
    read(s), read(e), read(t), read(g);
    --s;--e;
    graph[s].push_back(Bus(e, t, g));
  }
  
  using State=std::pair<int, std::pair<int, int>>;

  /* priority queue for Dijkstra Algorithm */
  std::priority_queue<State, std::vector<State>, std::greater<State>> q;

  std::vector<std::vector<bool>> visited(n, std::vector<bool>(k+1, 0));
  
  q.push({0, {0, 0}});
  while (!q.empty()) {
    int dist=q.top().first;
    int curr=q.top().second.first;
    int fw=q.top().second.second;
    q.pop();

    if (curr==n-1) {
      std::cout << dist;
      return 0;
    }
    if (visited[curr][fw]) continue;
    for (int i=fw;i<=k;++i) visited[curr][i]=1;
    
    for (const Bus &bus:graph[curr]) {
      const int &next=bus.e;
      const int &t=bus.t;
      const int &g=bus.g;

      if (!visited[next][fw]) q.push({(dist+g-1)/g*g+t, {next, fw}});
      if (fw<k && !visited[next][fw+1]) q.push({dist+t, {next, fw+1}});
    }
  }

  std::cout << "-1";
  return 0;
}
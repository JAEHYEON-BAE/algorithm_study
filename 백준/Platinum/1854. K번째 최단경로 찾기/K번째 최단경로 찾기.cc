// 1854

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>
#include <cmath>
#include <type_traits>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  #define OUTPUT_BUFFER_SIZE (1<<20)

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

struct Vertex
{
  int id;
  long long int dist;
  Vertex() {}
  Vertex(int id, long long int dist): id(id), dist(dist) {}

  bool operator<(const Vertex &o) const {
    return dist>o.dist;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int n, m, k;  read(n), read(m), read(k);
  int a, b, c;

  std::vector<std::vector<std::pair<int, long long int>>> graph(n);
  for (int i=0;i<m;++i) {
    read(a), read(b), read(c);
    --a;--b;
    graph[a].push_back({b, c});
  }

  /* store k-th shortest path for every vertices */
  std::vector<std::priority_queue<long long int>> dist(n);

  std::priority_queue<Vertex> pq;
  pq.push(Vertex(0, 0));
  dist[0].push(0);

  while (!pq.empty()) {
    int curr=pq.top().id;
    int curr_d=pq.top().dist;
    pq.pop();
    for (const auto &[next, cost]:graph[curr]) {
      long long int n_cost=curr_d+cost;
      if (dist[next].size()<k) {
        dist[next].push(n_cost);
        pq.push(Vertex(next, n_cost));
      }
      else if (dist[next].top()>n_cost) {
        dist[next].pop();
        dist[next].push(n_cost);
        pq.push(Vertex(next, n_cost));
      }
    }
  }
  for (int i=0;i<n;++i) {
    if (dist[i].size()<k) std::cout << "-1\n";
    else std::cout << dist[i].top() << '\n';
  }
 
  return 0;
}
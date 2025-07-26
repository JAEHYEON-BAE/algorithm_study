// 20010

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>

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

struct Edge
{
  int a, b, c;
  Edge() {}
  Edge(int a, int b, long long int c): a(a), b(b), c(c) {}
  bool operator<(const Edge &o) const {
    return c<o.c;
  }
};


class MST
{
  const int &n;
  std::vector<int> root, rank;
  std::vector<std::vector<std::pair<int, int>>> tree;

  int find(int x) {
    if (x==root[x]) return x;
    return root[x]=find(root[x]);
  }
  bool unite(int x, int y) {
    x=find(x); y=find(y);
    if (x==y) return false;
    if (rank[x]<rank[y]) root[x]=y;
    else {
      root[y]=x;
      if (rank[x]==rank[y]) ++rank[x];
    }
    return true;
  }

  int BFS() {
    std::vector<int> dist(n, -1);
    dist[0]=0;
    
    std::queue<int> q;
    q.push(0);

    int max_dist=0;
    int max_vertex;
    
    while (!q.empty()) {
      int curr=q.front();
      q.pop();
      for (const auto &p:tree[curr]) {
        int next=p.first;
        if (dist[next]!=-1) continue;
        int cost=p.second;

        dist[next]=dist[curr]+cost;
        q.push(next);

        if (dist[next]>max_dist) {
          max_dist=dist[next];
          max_vertex=next;
        }
      }
    }

    assert(q.empty());
    std::fill(dist.begin(), dist.end(), -1);
    q.push(max_vertex);
    dist[max_vertex]=0;

    int result=0;
    while (!q.empty()) {
      int curr=q.front();
      q.pop();
      for (const auto &p:tree[curr]) {
        int next=p.first;
        if (dist[next]!=-1) continue;
        int cost=p.second;

        dist[next]=dist[curr]+cost;
        q.push(next);

        if (dist[next]>result) result=dist[next];
      }
    }
    return result;
  };

public:
  MST(const int &n): n(n) {
    root.resize(n);
    for (int i=0;i<n;++i) root[i]=i;
    rank.assign(n, 0);
    tree.resize(n);
  }
  int connect(std::vector<Edge> &edges) {
    int cost=0;
    std::sort(edges.begin(), edges.end());
    for (const Edge &e:edges) {
      if (unite(e.a, e.b)) {
        cost+=e.c;
        tree[e.a].push_back({e.b, e.c});
        tree[e.b].push_back({e.a, e.c});
      }
    }
    return cost;
  }
  int max_cost() {
    return BFS();
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n, k;  read(n), read(k);

  MST x(n);
  std::vector<Edge> edges(k);
  for (int i=0;i<k;++i) {
    read(edges[i].a), read(edges[i].b), read(edges[i].c);
  }
  std::cout << x.connect(edges) << '\n' << x.max_cost();
 
  return 0;
}
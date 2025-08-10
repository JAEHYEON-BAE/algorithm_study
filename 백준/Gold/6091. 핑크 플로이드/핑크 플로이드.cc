// 2220

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
}

#endif

struct Path
{
  int u, v, w;
  Path() {}
  Path(int u, int v, int w): u(u), v(v), w(w) {}
  bool operator<(const Path &o) const {
    return w<o.w;
  }
};

class MST
{ 
  int n;
  std::vector<int> root, rank;
  std::vector<std::vector<int>> graph;

  int find(int x) {
    if (x==root[x]) return x;
    return root[x]=find(root[x]);
  }
  void unite(int x, int y) {
    int root_x=find(x), root_y=find(y);
    if (root_x==root_y) return;

    if (rank[root_x]<rank[root_y]) root[root_x]=root_y;
    else if (rank[root_x]>rank[root_y]) root[root_y]=root_x;
    else {
      root[root_y]=root_x;
      ++rank[root_x];
    }
    graph[x].push_back(y);
    graph[y].push_back(x);
    return;
  }

public:
  MST(int n): n(n) {
    root.resize(n);
    rank.assign(n, 0);
    for (int i=0;i<n;++i) root[i]=i;
    graph.resize(n);
  }

  void insert(const Path &p) {
    const auto &[u, v, w]=p;
    unite(u, v);
  }

  void print() {
    for (int i=0;i<n;++i) {
      std::cout << graph[i].size() << ' ';
      std::sort(graph[i].begin(), graph[i].end());
      for (const int &next:graph[i]) std::cout << next+1 << ' ';
      std::cout << '\n';
    }
    return;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  
  int n;  read(n);
  std::vector<Path> paths;
  for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
    int w;  read(w);
    paths.push_back(Path(i, j, w));
  }
  std::sort(paths.begin(), paths.end());
  MST mst(n);
  for (const Path &p:paths) mst.insert(p);

  mst.print();
  
  return 0;
}

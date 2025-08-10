// 19542

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_set>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>

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


int DFS(int node, std::vector<int> &child_depth, std::vector<bool> &visited, const std::vector<std::vector<int>> &graph, int &result, const int &d)
{
  visited[node]=1;
  int cnt=0;
  for (const int &next:graph[node]) if (!visited[next]) {
    ++cnt;
    child_depth[node]=std::max(child_depth[node], 1+DFS(next, child_depth, visited, graph, result, d));
  }
  if (child_depth[node]>=d) {
    result+=2;
    // DEBUG(node);
  }
  return child_depth[node];
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int n, s, d;  read(n), read(s), read(d);
  --s;
  std::vector<std::vector<int>> graph(n);
  for (int i=0;i<n-1;++i) {
    int x, y;  read(x), read(y);
    --x;--y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  std::vector<int> depth(n, -1);
  std::vector<int> parent(n, -1);
  depth[s]=0;
  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    for (const int &next:graph[curr]) if (depth[next]==-1) {
      depth[next]=depth[curr]+1;
      parent[next]=curr;
      q.push(next);
    }
  }

  std::vector<int> child_depth(n);
  std::vector<bool> visited(n, 0);
  int res=0;
  DFS(s, child_depth, visited, graph, res, d);
  if (child_depth[s]>=d) res-=2;

  // for (int i:child_depth) std::cout << i << ' ';
  // std::cout << std::endl;

  std::cout << res;
  return 0;
}


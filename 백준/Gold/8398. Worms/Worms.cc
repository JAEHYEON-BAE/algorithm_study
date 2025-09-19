// 8398

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int i=0;i<m;++i) {
    int a, b;  std::cin >> a >> b;
    --a;--b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int k;  std::cin >> k;
  std::vector<int> w(k);
  for (int &x:w) std::cin >> x, --x;

  std::vector<int> d(n, -1);
  
  std::queue<int> q;
  q.push(w[0]);
  d[w[0]]=0;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const int &v:graph[u]) if (d[v]==-1) {
      d[v]=1+d[u];
      q.push(v);
    }
  }
  int ml=0, mi=0;
  for (int i=1;i<k;++i) {
    if (d[w[i]]&1) {
      std::cout << "NIE";
      return 0;
    }
    if (d[w[i]]>ml) ml=d[w[i]], mi=i;
  }

  assert(q.empty());
  std::fill(d.begin(), d.end(), -1);
  
  q.push(w[mi]);
  d[w[mi]]=0;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const int &v:graph[u]) if (d[v]==-1) {
      d[v]=1+d[u];
      q.push(v);
    }
  }
  ml=0;
  for (int i=0;i<k;++i) ml=std::max(ml, d[w[i]]);

  std::cout << (ml>>1);
  return 0;
}
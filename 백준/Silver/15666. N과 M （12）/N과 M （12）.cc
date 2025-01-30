// 15666
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void DFS(int node, int depth, const int &m, const std::vector<std::vector<int>> &graph, std::vector<int> &path, std::vector<std::vector<int>> &results) 
{
  path[depth]=node;
  if (depth+1==m) {
    results.push_back(path);
    return;
  }
  for (const int &next: graph[node]) {
    DFS(next, depth+1, m, graph, path, results);
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> v;
  std::set<int> set;
  int x;
  for (int i=0;i<n;++i) {
    std::cin >> x; 
    set.insert(x);
  }
  for (const int &s:set) v.push_back(s);

  n=v.size();
  std::vector<std::vector<int>> graph(n);
  for (int i=0;i<n;++i) for (int j=i;j<n;++j) {
    graph[i].push_back(j);
  }

  std::vector<std::vector<int>> results;
  for (int i=0;i<n;++i) {
    std::vector<int> path(m);
    DFS(i, 0, m, graph, path, results);
  }
  std::sort(results.begin(), results.end());

  for (int i=0;i<results.size();++i) {
    const std::vector<int> &a = results[i];
    if (i>0 && results[i]==results[i-1]) continue;
    for (const int& b:a) std::cout << v[b] << ' ';
    std::cout << '\n';
  }
  
  return 0; 
}

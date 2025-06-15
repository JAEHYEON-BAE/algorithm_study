// 1115

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

void DFS(int node, std::vector<int> &v, std::vector<bool> &visited)
{
  if (visited[node]) return;
  visited[node]=1;
  DFS(v[node], v, visited);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  std::vector<bool> visited(n, 0);
  int cnt=0;
  for (int i=0;i<n;++i) if (!visited[i]) {
    DFS(i, v, visited);
    ++cnt;
  }

  std::cout << (cnt==1?0:cnt);
 
  return 0;
}

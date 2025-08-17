// 1135

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int DNQ(int node, const std::vector<std::vector<int>> &graph)
{
  if (graph[node].empty()) return 0;
  std::vector<int> v;
  for (const int &next:graph[node]) v.push_back(DNQ(next, graph));
  
  std::sort(v.begin(), v.end(), std::greater<>());
  int max=-1, n=v.size();
  for (int i=0;i<n;++i) {
    max=std::max(max, v[i]+i+1);
  }
  // std::cout << "DNQ(" << node << ") is " << max << '\n';
  return max;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> graph(n);

  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    if (x!=-1) graph[x].push_back(i);
  }
  std::cout << DNQ(0, graph);

  return 0;
}


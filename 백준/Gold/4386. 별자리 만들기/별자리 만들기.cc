// 4386

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

struct Edge
{
int u, v;
long double weight;
Edge(int _u, int _v, long double _weight) : u(_u), v(_v), weight(_weight) {}
bool operator<(const Edge& other) const 
{
    return weight < other.weight; 
}
};

inline long double distance(const std::pair<long double, long double>& a, const std::pair<long double, long double>& b)
{
  return std::sqrt(((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second)*(a.second-b.second)));
}

int find(const int& node, std::vector<int>& root)
{
  if (root[node]!=node) {
    root[node]=find(root[node], root);
  }
  return root[node];
}
bool unite(const int& x, const int& y, std::vector<int>& root, std::vector<int>& rank)
{
  int root_x = find(x, root);
  int root_y = find(y, root);
  if (root_x==root_y) return false;

  if (rank[root_x] < rank[root_y])
    root[root_x] = root_y;
  else if (rank[root_x] > rank[root_y])
    root[root_y] = root_x;
  else {
    root[root_y] = root_x;
    rank[root_x]++;
  }
  return true;
}

long double kruskal (const std::vector<Edge>& map, std::vector<int>& root, std::vector<int>& rank)
{
  long double result=0.0;
  for (const Edge& edge: map) {
    if (unite(edge.u, edge.v, root, rank)) {
      result += edge.weight;
    }
  }
  return result;
}

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);     
  std::cout.tie(NULL);

  int n;  std::cin >> n;
  std::vector<std::pair<long double, long double>> stars(n);
  std::vector<Edge> map;

  std::vector<int> root(n), rank(n, 0);
  
  for (int i=0;i<n;++i) {
    root[i] = i;
    std::cin >> stars[i].first >> stars[i].second;
    for (int j=0;j<i;++j) {
      map.push_back({i, j, distance(stars[i], stars[j])});
    }
  }
  std::sort(map.begin(), map.end());
  std::cout << std::fixed << std::setprecision(10) << kruskal(map, root, rank);
}
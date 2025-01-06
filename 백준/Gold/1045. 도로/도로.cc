// 1045

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Edge
{
int u, v;
Edge(int _u, int _v) : u(_u), v(_v) {}
bool operator<(const Edge& other) const
{
  if (u==other.u) return v<other.v;
  return u<other.u;
}
};

int find(const int& x, std::vector<int>& root)
{
  if (root[x]!=x) root[x]=find(root[x],root);
  return root[x];
}

bool unite(const int& x, const int& y, std::vector<int>& root, std::vector<int> rank)
{
  int root_x = find(x, root), root_y = find(y, root);
  if (root_x==root_y) return false;

  if (rank[x]<rank[y])
    root[root_x] = root_y;
  else if (rank[x]>rank[y])
    root[root_y] = root_x;
  else {
    ++rank[root_x];
    root[root_y] = root_x;
  }

  return true;
}

std::vector<Edge> kruskal(const std::vector<Edge>& map, std::vector<int>& root, std::vector<int>& rank, std::vector<bool>& used)
{
  // std::cout << "Calling KRUSKAL\n";
  std::vector<Edge> result;
  for (int i=0;i<map.size();++i) {
    const Edge edge = map[i];
    if (unite(edge.u, edge.v, root, rank)) {
      result.push_back({edge.u, edge.v});
      used[i] = true;
      // std::cout << "\tConnecting: {" << edge.u << ", " << edge.v << "}\n";
    }
  }
  return result;
}

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);     
  std::cout.tie(NULL);

  int n, m;  std::cin >> n >> m;
  std::vector<Edge> map;
  std::vector<int> root(n), rank(n, 0);
  for (int i=0;i<n;++i) root[i] = i;
  
  int Y_n=0;
  for (int i=0;i<n;++i) {
    std::string str;
    std::cin >> str;
    for (int j=i+1;j<n;++j) {
      if (str[j]=='Y') {
        map.push_back({i, j});
        ++Y_n;
      }
    }
  }

  if (Y_n < m) {
    std::cout << -1;
    return 0;
  }
  std::sort(map.begin(), map.end());
  std::vector<bool> used(map.size(), false);
  std::fill(used.begin(), used.end(), false);
  std::vector<Edge> mst = kruskal(map, root, rank, used);

  // std::cout << "mst size = " << mst.size() << std::endl;
  
  if (mst.size()!=n-1) {
    std::cout << -1;
    return 0;
  }
  if (mst.size()>m) {
    std::cout << -1;
    return 0;
  }
  while (mst.size()!=m) {
    for (int i=0;i<map.size();++i) {
      if (!used[i]) {
        const Edge edge = map[i];
        mst.push_back({edge.u, edge.v});
        used[i] = true;
        // std::cout << "\tConnecting: {" << edge.u << ", " << edge.v << "}\n";
        break;
      }
    }
  }

  std::vector<int> result(n, 0);
  for (const Edge& edge: mst) {
    ++result[edge.u];
    ++result[edge.v];
  } 
  for (const int& x: result) {
    std::cout << x << ' ';
  }
  
  return 0;
}
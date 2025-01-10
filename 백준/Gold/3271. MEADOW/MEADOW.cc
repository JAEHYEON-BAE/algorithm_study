// 3271

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point 
{
  int x, y;

  bool operator<(const Point& other) const {
    if (y==other.y) return x<other.x;
    return y<other.y;
  }

  int operator-(const Point& other) const {
    return (x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
  }
};

struct Edge
{
  int s, e;
  int weight;

  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

int find(int x, std::vector<int>& root) 
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}

bool unite(int x, int y, std::vector<int>& root, std::vector<int>& rank)
{
  int rootX = find(x, root);  int rootY = find(y, root);
  if (rootX==rootY) return false;

  if (rank[rootX]<rank[rootY]) root[rootX]=rootY;
  else if (rank[rootX]>rank[rootY]) root[rootY]=rootX;
  else {
    root[rootY] = rootX;
    ++rank[rootX];
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int f, b;  std::cin >> f >> b;
  std::vector<Point> flowers(f);
  for (int i=0;i<f;++i)  std::cin >> flowers[i].x >> flowers[i].y;

  std::vector<Edge> edges;
  for (int i=0;i<f;++i) for (int j=i+1;j<f;++j) {
    edges.push_back({i, j, flowers[i]-flowers[j]});
  }
  std::sort(edges.begin(), edges.end());

  std::vector<int> root(f), rank(f, 0);
  for (int i=0;i<f;++i) root[i] = i;

  int result = 0;

  int i=0;
  for (int n=0;n<f-b;) {
    Edge edge = edges[i];
    // std::cout << edge.s << ' ' << edge.e << ' ' << edge.weight << std::endl;
    if (unite(edge.s, edge.e, root, rank)) {
      result = edge.weight;
      ++n;
    }
    else ++i;
  }

  std::cout << std::fixed << std::setprecision(2) << std::sqrt(static_cast<long double>(result));
}


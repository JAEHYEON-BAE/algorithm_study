// 14938

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF = (~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, r; std::cin >> n >> m >> r;
  std::vector<int> items(n);
  for (int i=0;i<n;++i) std::cin >> items[i];
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, (~0u)>>1));
  int a, b, l;
  for (int i=0;i<r;++i) {
    std::cin >> a >> b >> l;
    dist[--a][--b]=l;  dist[b][a]=l;
  }
  for (int i=0;i<n;++i) dist[i][i]=0;

  for (int k=0;k<n;++k) for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    if (dist[i][k]!=INF && dist[k][j]!=INF) {
      dist[i][j]=std::min(dist[i][j], dist[i][k]+dist[k][j]);
    }
  }

  int max=0;
  for (int i=0;i<n;++i) {
    int tmp=0;
    for (int j=0;j<n;++j) {
      if (dist[i][j]<=m) tmp+=items[j];
    }
    max=std::max(max, tmp);
  }
  std::cout << max;
  
  return 0; 
}

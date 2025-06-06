// 14442

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <array>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  ++k;
  std::vector<std::vector<bool>> map(n, std::vector<bool>(m));
  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<m;++j) map[i][j]=(line[j]=='1');
  }
  
  std::vector<std::vector<std::vector<int>>> dist(n, std::vector<std::vector<int>>(m, std::vector<int>(k, INF)));

  std::vector<std::vector<std::vector<bool>>> visited(n, std::vector<std::vector<bool>>(m, std::vector<bool>(k, 0)));

  std::queue<std::array<int, 3>> q;
  q.push({0, 0, 0});
  dist[0][0][0]=1;
  visited[0][0][0]=1;

  int dr[4]={0, 1, 0, -1};
  int dc[4]={1, 0, -1, 0};

  while (!q.empty()) {
    int cr=q.front()[0];
    int cc=q.front()[1];
    int cb=q.front()[2];

    q.pop();
    for (int d=0;d<4;++d) {
      int nr=cr+dr[d];
      int nc=cc+dc[d];
      if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
      int nb=cb+(map[nr][nc]);

      if (nb>=k || visited[nr][nc][nb]) continue;
      visited[nr][nc][nb]=1;
      dist[nr][nc][nb]=1+dist[cr][cc][cb];
      q.push({nr, nc, nb});
    }
  }

  int res=*std::min_element(dist[n-1][m-1].begin(), dist[n-1][m-1].end());
  std::cout << ((res==INF)?-1:res);
  
  return 0;
}
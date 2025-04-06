// 27924
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};

void solve(std::vector<std::queue<std::pair<int, int>>> &dv, std::vector<std::vector<int>> &water, const std::vector<std::vector<int>> &h, const int &n, const int &m)
{
  std::vector<std::vector<bool>> visited(n+2, std::vector<bool>(m+2, 0));

  visited[0][0]=1;
  dv[0].push({0, 0});

  for (int i=0;i<=10'000;++i) {
    while (!dv[i].empty()) {
      int r=dv[i].front().first;
      int c=dv[i].front().second;
      dv[i].pop();
      water[r][c]=i;
      for (int k=0;k<4;++k) {
        int _r=r+dr[k];
        int _c=c+dc[k];
        if (_r>=0 && _r<n+2 && _c>=0 && _c<m+2) {
          if (visited[_r][_c]) continue;

          visited[_r][_c]=1;
          if (h[_r][_c]<=i) dv[i].push({_r, _c});
          else dv[h[_r][_c]].push({_r, _c});
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> h(n+2, std::vector<int>(m+2, 0));

  std::vector<std::queue<std::pair<int, int>>> dv(10'001);
  for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) {
    std::cin >> h[i][j];
  }
  std::vector<std::vector<int>> water=h;

  solve(dv, water, h, n, m);

  int result=0;
  for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) result+=water[i][j]-h[i][j];
  
  std::cout << result;
  return 0;
}
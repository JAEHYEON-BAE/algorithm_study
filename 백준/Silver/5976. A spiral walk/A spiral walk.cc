// 5967

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int dr[4]={0, 1, 0, -1};
constexpr int dc[4]={1, 0, -1, 0};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));

  int r=0, c=0, id=1;
  v[r][c]=id;
  for (int d=0;d<4;++d, d%=4) {
    bool FLAG=1;
    while (1) {
      int nr=r+dr[d];
      int nc=c+dc[d];
      if (nr<0 || nr>=n || nc<0 || nc>=n || v[nr][nc]!=0) break;

      FLAG=0;
      v[nr][nc]=++id;
      r=nr, c=nc;
    }
    if (FLAG) break;
  }

  for (const auto &r:v) {
    for (const int &x:r) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}
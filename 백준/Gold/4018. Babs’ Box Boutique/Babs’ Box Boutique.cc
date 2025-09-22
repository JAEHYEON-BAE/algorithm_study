// 4018

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bitset>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct Box
{
  int x, y, z;
  Box() {};
  Box(int x, int y, int z): x(x), y(y), z(z) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);


  int tc=1, n;
  while (std::cin >> n) {
    if (!n) break;
    
    std::vector<int> ord(n);
    for (int i=0;i<n;++i) ord[i]=i;

    std::vector<Box> boxes(n);
    for (int i=0;i<n;++i) std::cin >> boxes[i].x >> boxes[i].y >> boxes[i].z;

    // dp[bit][x][y] := bit상태만큼 쌓았을 때, 마지막 상태 x y 인 경우 가능?

    std::vector<std::vector<std::vector<bool>>> dp(1<<n, std::vector<std::vector<bool>>(21, std::vector<bool>(21, 0)));
    dp[0][20][20]=1;
    int max=0;

    for (int i=0;i<(1<<n);++i) {
      for (int x=0;x<=20;++x) for (int y=0;y<=20;++y) {
        if (dp[i][x][y]) {
          max=std::max(max, __builtin_popcount(i));

          // std::cout << std::bitset<4>(i) << '\t' << x << ' ' << y << std::endl;
          for (int j=0;j<n;++j) if (!(i&(1<<j))) {
            const auto &[bx, by, bz]=boxes[j];

            if ((bx<=x && by<=y) || (by<=x && bx<=y)) {
              dp[i|1<<j][bx][by]=1;
            }
            if ((bx<=x && bz<=y) || (bz<=x && bx<=y)) {
              dp[i|1<<j][bx][bz]=1;
            }
  
            if ((by<=x && bz<=y) || (bz<=x && by<=y)) {
              dp[i|1<<j][by][bz]=1;
            }
          }
        }
      }
    }
    std::cout << "Case " << tc++ << ": " << max << '\n';
  }

  
  return 0;
}
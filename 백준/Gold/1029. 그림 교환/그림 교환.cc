// 1029

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

std::vector<std::vector<std::vector<int>>> dp;

int resell(int visited, int artist, int price, const int &n, const std::vector<std::vector<int>> &map)
{
  int &tmp=dp[visited][artist][price];
  if (tmp!=-1) return tmp;

  tmp=0;
  for (int i=1;i<n;++i) {
    if (!(visited&(1<<i)) && map[artist][i]>=price) {
      int update=visited|(1<<i);
      tmp=std::max(tmp, 1+resell(update, i, map[artist][i], n, map));
    }
  }
  return tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<std::vector<int>> map(n, std::vector<int>(n));

  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<n;++j) {
      map[i][j]=line[j]-'0';
    }
  }
  
  dp.assign(1<<n, std::vector<std::vector<int>>(n, std::vector<int>(10, -1)));
  /** dp[x][y][z] = 
    *  x: bitmasking(visited)
    *  y: last artist
    *  z: last price
    *  value: total count
    */
  std::cout << 1+resell(1, 0, 0, n, map);

  
  return 0; 
}
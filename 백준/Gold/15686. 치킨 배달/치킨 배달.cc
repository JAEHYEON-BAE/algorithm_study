// 15666
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

struct Point
{
  int r, c;
  Point(int r, int c): r(r), c(c) {}
  int operator -(const Point &other) const {
    return abs(r-other.r)+abs(c-other.c);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<Point> houses, chickens;
  // int house_cnt=0, chicken_cnt=0;
  std::vector<std::vector<int>> map(n, std::vector<int>(n));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    std::cin >> map[i][j];
    if (map[i][j]==1) houses.emplace_back(Point(i, j));
    else if (map[i][j]==2) chickens.emplace_back(Point(i, j));
  }
  
  std::vector<std::vector<int>> chick_dist(houses.size(), std::vector<int>(chickens.size()));
  for (int i=0;i<houses.size();++i) for (int j=0;j<chickens.size();++j) {
    chick_dist[i][j] = houses[i]-chickens[j];
  }

  std::vector<bool> tmp(chickens.size(), false);
  std::fill(tmp.begin(), tmp.begin()+m, true);

  int result = (~0u)>>1;
  do {
    int res_tmp=0;
    for (int i=0;i<houses.size();++i) {
      std::vector<int> ch_tmp = chick_dist[i];
      for (int j=0;j<tmp.size();++j) {
        if (!tmp[j]) ch_tmp[j]=(~0u)>>1;
      }
      res_tmp += *std::min_element(ch_tmp.begin(), ch_tmp.end());
    }

    result = std::min(result, res_tmp);
  } while (std::prev_permutation(tmp.begin(), tmp.end()));

  std::cout << result;
  
  return 0; 
}

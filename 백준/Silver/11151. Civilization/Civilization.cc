// 11151

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF = (~0u) >> 2;

int cnt(int x) {
  int tmp = 0;
  do
    ++tmp;
  while (x &= x - 1);
  return tmp;
}

struct Region {
  int w, c, f;
  Region(int w, int c, int f) : w(w), c(c), f(f) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n, w, c, f, _w, _c, _f;
    std::cin >> n >> w >> c >> f;
    std::vector<Region> regions;
    int total_w=0, total_c=0, total_f=0;
    for (int i=0;i<n;++i) {
      std::cin >> _w >> _c >> _f;
      regions.emplace_back(Region(_w, _c, _f));
      total_w += _w;
      total_c += _c;
      total_f += _f;
    }

    if (total_w < w || total_c < c || total_f < f) {
      std::cout << "game over\n";
      continue;
    }

    int min = n;
    for (int i=0;i<(1<<n);++i) {
      int tmp_w=0, tmp_c=0, tmp_f=0;
      for (int j=0;j<n;++j) {
        if (i>>j==0) break;
        if (i>>j&1) {
          tmp_w += regions[j].w;
          tmp_f += regions[j].f;
          tmp_c += regions[j].c;
        }
      }
      if (tmp_w >= w && tmp_c >= c && tmp_f >= f) {
        min = std::min(min, __builtin_popcount(i));
      }
    }
    std::cout << min << '\n';
  }
  return 0;
}
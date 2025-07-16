// 17406

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>

struct CMD
{
  int r, c, s;
  CMD(){}
  CMD(int r, int c, int s): r(r), c(c), s(s) {}

  bool operator<(const CMD &o) const {
    if (r==o.r) {
      if (c==o.s) return s<o.s;
      return c<o.c;
    }
    return r<o.r;
  }
};

void rotate(std::vector<std::vector<int>> &v, int r, int c, int s)
{
  --r;--c;
  for (int layer=1;layer<=s;++layer) {
    int top=r-layer, left=c-layer, bottom=r+layer, right=c+layer;

    int tmp=v[top][left];
    for (int i=left+1;i<=right;++i) std::swap(tmp, v[top][i]);
    for (int i=top+1;i<=bottom;++i) std::swap(tmp, v[i][right]);
    for (int i=right-1;i>=left;--i) std::swap(tmp, v[bottom][i]);
    for (int i=bottom-1;i>=top;--i) std::swap(tmp, v[i][left]);
  }
}
int min_sum(const std::vector<std::vector<int>> &v) 
{
  int min=10000;
  for (const auto &c:v) {
    int sum=0;
    for (const int &x:c) sum+=x;
    min=std::min(min, sum);
  }
  return min;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> v(n, std::vector<int>(m));
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) std::cin >> v[i][j];

  std::vector<CMD> q(k);
  for (int i=0;i<k;++i) std::cin >> q[i].r >> q[i].c >> q[i].s;

  std::sort(q.begin(), q.end());

  int min=10000;
  do {
    std::vector<std::vector<int>> copy=v;
    for (int i=0;i<k;++i) {
      rotate(copy, q[i].r, q[i].c, q[i].s);
    }
    min=std::min(min, min_sum(copy));
  } while (std::next_permutation(q.begin(), q.end()));

  std::cout << min;
  return 0;
}
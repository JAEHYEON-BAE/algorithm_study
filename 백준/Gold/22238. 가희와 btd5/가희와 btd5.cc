// 2987

#include <iostream>
#include <algorithm>
#include <vector>

int gcd(int a, int b)
{
  a = std::abs(a); b = std::abs(b);
  if (b==0) return (a)? a: 1;
  if (a%b==0) return b;
  return gcd(b, a%b);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> hp(n);
  int x, y;
  for (int i=0;i<n;++i) std::cin >> x >> y >> hp[i];

  int g = gcd(x, y);
  x/=g;  y/=g;
  std::sort(hp.begin(), hp.end());

  int d_sum = 0;
  while (m--) {
    int _x, _y, _d;  std::cin >> _x >> _y >> _d;
    int _g = gcd(_x, _y);
    _x/=_g;  _y/=_g;
    if (x==_x && y==_y) {
      d_sum += _d;
    }
    if (d_sum>=1e9) d_sum=1e9;
    
    std::cout << std::distance(std::upper_bound(hp.begin(), hp.end(), d_sum), hp.end()) << '\n';
  }
 }

// 3709

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

struct Tetra
{
  int a, b, c, d;
  Tetra(){}
  Tetra(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
  bool is_same(const Tetra &o) const {
    if (a==o.a && b==o.b && c==o.c && d==o.d) return 1;

    Tetra candidates[4]={
      Tetra(o.a, o.b, o.c, o.d),
      Tetra(o.b, o.d, o.c, o.a),
      Tetra(o.c, o.a, o.b, o.d),
      Tetra(o.d, o.c, o.b, o.a)
    };
    for (int i=0;i<4;++i) {
      Tetra &x=candidates[i];
      if (x.a!=a) continue;

      if (x.b==b && x.c==c && x.d==d) return 1;
      else if (x.b==c && x.c==d && x.d==b) return 1;
      else if (x.b==d && x.c==b && x.d==c) return 1;
    }
    return 0;
  }
};

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int k;  std::cin >> k;
  while (k--) {
    Tetra x, y;
    std::cin >> x.a >> x.b >> x.c >> x.d >> y.a >> y.b >> y.c >> y.d;
    std::cout << x.is_same(y) << '\n';
  }

  return 0;
}

// 12705

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int area(int x1, int y1, int x2, int y2)
{
  return std::abs(x1*y2 - x2*y1);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int c=1;c<=t;++c) {
    int n, m, a;  std::cin >> n >> m >> a;
    ++n;++m;

    if (a>n*m) {
      std::cout << "Case #" << c << ": IMPOSSIBLE\n";
      continue;
    }

    // (0, 0)과 다른 두 점 선택하여 넓이 계산
    bool DONE=0;
    for (int p1=1;p1<n*m-1;++p1) {
      for (int p2=p1+1;p2<n*m;++p2) {
        int x1=p1/m, y1=p1%m;
        int x2=p2/m, y2=p2%m;
  
        if (area(x1, y1, x2, y2)==a) {
          DONE=1;
          std::cout << "Case #" << c << ": 0 0 " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
          break;
        }
      }
      if (DONE) break;
    }
    if (!DONE)  std::cout << "Case #" << c << ": IMPOSSIBLE\n";
  }
  
  return 0;
}
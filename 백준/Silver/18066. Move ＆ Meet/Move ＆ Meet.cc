// 18066

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int x1, y1, d1, x2, y2, d2;
  std::cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

  long long int d=std::abs(x1-x2)+std::abs(y1-y2);
  long long int dx=x2-x1, dy=y2-y1, ax=std::abs(x1-x2), ay=std::abs(y1-y2);
  if(ax+ay>d1+d2 || (ax+ay+d1+d2)%2==1){
      std::cout << "impossible";
  } else {
      if(d1 >= ax){
          x1 = x2;
          d1 -= ax;
          if(d1 >= ay){
              y1 = y2;
              d1 -= ay;
              if(d1&1)++y1;
          } else {
              y1 += d1*(ay/dy);
          }
      } else {
          x1 += d1*(ax/dx);
      }
      std::cout << x1 << " " << y1;
  }

  return 0;
}
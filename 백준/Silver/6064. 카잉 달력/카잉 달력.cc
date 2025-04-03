// 6064
#include <iostream>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

inline int GCD(int a, int b)
{
  while (b) {
    int tmp=b;
    b=a%b;
    a=tmp;
  }
  return a;
}

inline int LCM(int a, int b)
{
  int g=GCD(a, b);
  return a/g*b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int m, n, x, y;  std::cin >> m >> n >> x >> y;
    // k%m=x, k%n=y
    if (x>m || y>n) {std::cout << -1 << '\n'; continue;}

    int lcm=LCM(m, n);
    bool FLAG=1;
    for (int i=0;;++i) {
      int tmp=m*i+x;
      if (tmp>lcm) break;
      if (tmp%n==y%n) {
        std::cout << tmp << '\n';
        FLAG=0;
        break;
      }
    }
    if (FLAG) std::cout << -1 << '\n'; 
  }

  return 0;
}
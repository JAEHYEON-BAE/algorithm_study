// 2166

#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
  long double x, y;
};

long double area(const std::vector<Point>& p, const int& n)
{
  long double result = 0.0L;
  for (int i=0;i<n;++i) {
    result += p[i].x*p[(i+1)%n].y - p[(i+1)%n].x*p[i].y;
  }
  return std::fabs(result)/2;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cout.precision(1);

  int n;  std::cin >> n;
  std::vector<Point> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i].x >> v[i].y;

  std::cout << std::fixed << area(v, n);
}


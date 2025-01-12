// 2175

#include <iostream>
#include <algorithm>
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

Point mid(const Point& a, const Point& b)
{
  return {(a.x+b.x)/2, (a.y+b.y)/2};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  Point points[8];

  std::cin >> points[0].x >> points[0].y >> points[2].x >> points[2].y >> points[4].x >> points[4].y >> points[6].x >> points[6].y;

  long double tot_area = area({points[0], points[2], points[4], points[6]}, 4);
  
  points[1] = mid(points[0], points[2]);
  points[3] = mid(points[2], points[4]);
  points[5] = mid(points[4], points[6]);
  points[7] = mid(points[6], points[0]);

  std::pair<long double, std::pair<long double, long double>> result;
  result = {1'987'654'321, {0, 0}};
  long double half, d;
  for (int i=0;i<8;++i) {
    if (i%2) {
      for (int j=i+2;j<=i+6;++j) {
        if (j<i+4) half = area({points[i], points[(i+1)%8], points[j%8]}, 3);
        if (j==i+4) half = area({points[i], points[(i+1)%8], points[(i+3)%8], points[j%8]}, 4);
        if (j>i+4) half = area({points[i], points[j%8], points[(i+7)%8]}, 3);

        d = std::fabs(tot_area - half*2);
        if (d<result.first) result = {d, {half, tot_area-half}};
      }
    }
    else {
      for (int j=i+3;j<=i+5;++j) {
        if (j==i+5) half = area({points[i], points[j%8], points[(i+6)%8]}, 3);
        else half = area({points[i], points[(i+2)%8], points[j%8]}, 3);
        d = std::fabs(tot_area - half*2);
        if (d<result.first) result = {d, {half, tot_area-half}};
      }
    }
  }

  std::cout.precision(5);
  std::cout << std::fixed << std::min(result.second.first, result.second.second) << ' ' << std::max(result.second.first, result.second.second);
}


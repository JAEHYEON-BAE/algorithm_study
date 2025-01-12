// 11664

#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
  long double x, y, z;

  inline Point operator+(const Point& other) const {
    return {x+other.x, y+other.y, z+other.z};
  }
  inline Point operator-(const Point& other) const {
    return {x-other.x, y-other.y, z-other.z};
  }

  inline Point operator*(const long double& n) const {
    return {x*n, y*n, z*n};
  }
  inline long double operator*(const Point& other) const {
    return x*other.x+y*other.y+z*other.z;
  }

  inline long double dist(const Point& other) const {
    return std::sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y)+(z-other.z)*(z-other.z));
  }
};



int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cout.precision(10); std::cout << std::fixed;
  
  Point v[3];
  std::cin >> v[0].x >> v[0].y >> v[0].z >> v[1].x >> v[1].y >> v[1].z >> v[2].x >> v[2].y >> v[2].z;

  long double t = ((v[2]-v[0])*(v[1]-v[0])) / ((v[1]-v[0])*(v[1]-v[0]));
  if (t<=0) std::cout << v[0].dist(v[2]);
  else if (t>=1) std::cout << v[1].dist(v[2]);
  else std::cout << v[2].dist(v[0] + (v[1]-v[0])*t);
}


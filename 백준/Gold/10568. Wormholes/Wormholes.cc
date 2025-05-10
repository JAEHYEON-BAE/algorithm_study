// 10568

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

struct Point
{
  long double x, y, z;
  Point(): x(0), y(0), z(0) {}
  Point(long double x, long double y, long double z): 
    x(x), y(y), z(z) {}
  long double operator- (const Point &p) const {
    return std::sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int tc=1;tc<=t;++tc) {
    int p;  std::cin >> p;
    std::string name; 
    std::unordered_map<std::string, int> idx;
    std::vector<Point> points(p);
    for (int i=0;i<p;++i) {
      std::cin >> name;
      idx[name]=i;
      std::cin >> points[i].x >> points[i].y >> points[i].z;
    }
    std::vector<std::vector<long double>> dist(p, std::vector<long double>(p, -1));
    for (int i=0;i<p;++i) for (int j=0;j<p;++j) {
      if (i==j) dist[i][j]=0;
      dist[i][j]=points[i]-points[j];
    }
    int w;  std::cin >> w;
    std::string u, v;
    for (int i=0;i<w;++i) {
      std::cin >> u >> v;
      dist[idx.at(u)][idx.at(v)]=0;
    }

    for (int k=0;k<p;++k) {
      for (int i=0;i<p;++i) for (int j=0;j<p;++j) {
        if (i==j) dist[i][j]=0;
        dist[i][j]=std::min(dist[i][k]+dist[k][j], dist[i][j]);
      }
    }

    int q;  std::cin >> q;
    std::cout << "Case " << tc << ':' << '\n';
    while (q--) {
      std::cin >> u >> v;
      std::cout << "The distance from " << u << " to " << v << " is " << static_cast<int>(std::round(dist[idx.at(u)][idx.at(v)])) << " parsecs.\n";
    }
  }
  
  
  return 0;
}
// 2261

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

struct Point
{
  int x=0, y=0;

  bool operator<(const Point& other) const {
    if (x==other.x)  return y<other.y;
    return x<other.x;
  }
  bool operator==(const Point& other) const {
    return x==other.x && y==other.y;
  }
  int operator-(const Point& other) const {
    return (x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
  }
};

inline bool compareY(const Point& a, const Point&b)
{
  return a.y<b.y;
}

inline int bandClosest(const std::vector<Point>& band, int size, int d)
{
  int min = d;
  for (int i=0;i<size-1;++i)
    for (int j=i+1;j<size && (band[j].y-band[i].y)<min; ++j) { 
      if (band[j].y - band[i].y >= min) break;
      min = std::min(min, band[i]-band[j]);
    }
  return min;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int INF = (~0u)>>1;
  
  int n;  std::cin >> n;
  std::vector<Point> points(n), band(n);
  for (int i=0;i<n;++i) {
    std::cin >> points[i].x >> points[i].y;
  }
  std::sort(points.begin(), points.end());

  /** Draw a vertical line that divides the number of points
    * left area:  points[0] ~ points[n/2-1]
    * right area: points[n/2] ~ points[n-1]
    *
    * DnQ:
    *   min(whole) = min(min(left), min(right), bridge)
    * 
    * the bridge is the smallest line 
    *     that connects left area and right area
    */
  
  auto CPP = [&INF, &points, &band] (auto&& CPP, const int s, const int e) -> int {
   
    if (s==e) return INF;
    if (points[s]==points[e]) return 0;
    if (e-s==1) return points[e]-points[s];

    if (e-s<=3) {
      int min_dist = INF;
      for(int i=s; i<=e-1; ++i)
        for(int j=i+1; j<=e; ++j)
          min_dist = std::min(min_dist, points[i]-points[j]);
      return min_dist;
    }
    
    int mid = (s+e)/2;

    // merge!
    int d = std::min(CPP(CPP, s, mid), CPP(CPP, mid+1, e));

    int size = 0;
    for (int i = 0; i<e+1-s; i++)
      if (std::abs(points[i].x - points[mid].x) < d)
        band[size++] = points[i];

    std::sort(band.begin(), band.begin()+size, compareY);

    for (int i=0;i<size-1;++i) for (int k=i+1;k<size;++k) { 
      if (band[k].y - band[i].y >= d) break;
      d = std::min(d, band[i]-band[k]);
    }

    return d;
  };

  std::cout << CPP(CPP, 0, n-1);
}

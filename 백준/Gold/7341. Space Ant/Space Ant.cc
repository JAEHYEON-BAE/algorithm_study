// 7341

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

struct Point 
{
  int idx; long double x, y;
  bool operator<(const Point& other) const {
    if (y==other.y) return x<other.x;
    return y<other.y;
  }

  long double size() const {
    return std::sqrt(x*x+y*y);
  }

  long double ccw(const Point& other) const {
    return x*other.y - y*other.x;
  }

  long double dot(const Point& other) const {
    return x*other.x + y*other.y;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  const int INF = (~0u)>>1;
  int m;  std::cin >> m;
  while (m--) {
    int n;  std::cin >> n;
    std::vector<Point> points(n);

    for (int i=0;i<n;++i) {
      std::cin >> points[i].idx >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end());


    // brute force search: select the node who has least gradient diff.
    // start from (0, points[0].y) ~ points[0]
    Point prev = {0, 0, points[0].y};
    Point curr = points[0];

    std::vector<bool> visited(n+1, false);
    std::vector<int> result(n);
    
    visited[points[0].idx] = true;
    result[0] = points[0].idx;

    for (int i=1;i<n;++i) {
      long double tmp = INF;
      Point tmp_p;
      for (const Point& p: points) if (!visited[p.idx]) {
        // vector prev->curr
        Point a; a.x = curr.x-prev.x, a.y = curr.y-prev.y;
        long double size = a.size();
        a.x/=size; a.y/=size;

        // vector curr->p
        Point b; b.x = p.x-curr.x, b.y = p.y-curr.y;
        size = b.size();
        b.x/=size; b.y/=size;

        long double _ccw = a.ccw(b);
        if (a.dot(b)<0) _ccw=2-_ccw;
                
        if (_ccw<tmp) {
          tmp = _ccw;
          tmp_p = p;
        }
      }
      prev = curr;
      curr = tmp_p;
      visited[tmp_p.idx] = true;
      result[i] = tmp_p.idx;
    }
    
    std::cout << n;
    for (const int& x: result) {
      std::cout << ' ' << x;
    }
    std::cout << '\n';
  }
}


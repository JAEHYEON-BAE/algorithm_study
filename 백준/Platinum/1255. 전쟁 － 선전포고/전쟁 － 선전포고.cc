// 1255

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>
#include <iomanip>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ld=long double;


struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  bool operator==(const Point &o) const {
    return x==o.x && y==o.y;
  }
};

ld distance(const Point &a, const Point &b)
{
  int tmp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
  return std::sqrt(static_cast<ld>(tmp));
}

namespace std
{
  template <>
  struct hash<Point> {
    size_t operator()(const Point &p) const {
      return p.x*1001+p.y;
    }
  };
}

std::ostream& operator<<(std::ostream& os, const Point &p) {
  os << '(' << p.x << ',' << p.y << ')';
  return os;
}

struct Line
{
  Point a, b;
  Line() {}
  Line(Point a, Point b): a(a), b(b) {}
};

inline int CCW(const Point &a, const Point &b, const Point &c)
{
  int d=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
  return (d>0)-(d<0);
}

bool cross(const Line &l1, const Line &l2) 
{
  return (CCW(l1.a, l1.b, l2.a)*CCW(l1.a, l1.b, l2.b)<0 && CCW(l2.a, l2.b, l1.a)*CCW(l2.a, l2.b, l1.b)<0);
}

struct Edge
{
  int to;
  ld w;
  Edge() {}
  Edge(int to, ld w): to(to), w(w) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  
  std::vector<Point> points;

  std::vector<ld> v(n);

  std::vector<Line> lines;
  
  for (int i=0;i<n;++i) {
    std::string s;
    std::cin >> s >> v[i];
    int x, y;
    std::string tmp;
    for (const char &c:s) {
      if (c=='(') continue;
      else if (c==',') x=std::stoi(tmp), tmp.clear();
      else if (c==')') y=std::stoi(tmp);
      else tmp.push_back(c);
    }
    
    Point p(x, y);
    
    points.push_back(p);
  }
  for (int i=0;i<m;++i) {
    std::string s;
    std::cin >> s;
    int x, y;
    std::string tmp;
    for (const char &c:s) {
      if (c=='(') continue;
      else if (c==',') x=std::stoi(tmp), tmp.clear();
      else if (c==')') y=std::stoi(tmp);
      else tmp.push_back(c);
    }
    Point a(x, y);
    points.push_back(a);
    
    std::cin >> s >> s;
    tmp.clear();
    for (const char &c:s) {
      if (c=='(') continue;
      else if (c==',') x=std::stoi(tmp), tmp.clear();
      else if (c==')') y=std::stoi(tmp);
      else tmp.push_back(c);
    }
    Point b(x, y);
    points.push_back(b);

    lines.push_back(Line(a, b));
  }

  int size=points.size();
  std::vector<std::vector<Edge>> G(1+size);
  for (int i=0;i<size;++i) {
    const Point &p=points[i];
    bool VALID=1;
    for (const Line &l:lines) {
      if (cross(Line(p, Point(p.x, 0)), l)) {VALID=0; break;}
    }
    if (VALID) G[size].push_back(Edge(i, static_cast<ld>(p.y)));
  }
  

  for (int i=0;i<size;++i) for (int j=0;j<size;++j) if (i!=j) {
    bool VALID=1;
    for (const Line &l:lines) {
      if (cross(l, Line(points[i], points[j]))) {VALID=0; break;}
    }
    if (!VALID) continue;

    ld d=distance(points[i], points[j]);
    G[i].push_back(Edge(j, d));
    G[j].push_back(Edge(i, d));
    
    // std::cerr << points[i] << '-' << points[j] << '\t' << d << std::endl;
  }

  const ld INF=1'000'000'000.0L;
 
  std::vector<ld> dist(1+size, INF);
  std::priority_queue<std::pair<ld, int>, std::vector<std::pair<ld, int>>, std::greater<std::pair<ld, int>>> pq;

  dist[size]=0.0L;
  pq.push({0.0L, size});

  while (!pq.empty()) {
    auto [w, u]=pq.top();
    pq.pop();
    if (dist[u]<w) continue;
    for (const auto &[v, d]:G[u]) {
      if (w+d<dist[v]) {
        dist[v]=w+d;
        pq.push({dist[v], v});
      }
    }
  }

  // std::cerr << "FROM " << points[s] << ": " << dist[size] << std::endl;
  ld res=0.0L;
  for (int i=0;i<n;++i) {
    res=std::max(res, dist[i]/v[i]);
  }
  
  std::cout << std::fixed << std::setprecision(1) << res;
  return 0;
}
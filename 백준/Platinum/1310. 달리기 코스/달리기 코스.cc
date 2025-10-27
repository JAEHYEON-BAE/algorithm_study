// 1310

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
#define INPUT_BUFFER_SIZE (1<<20)
char get()
{
  static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
  if (S==T) {
    T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
    if (S==T) return EOF;
  }
  return *S++;
}
template <typename T>
void read(T &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

struct Point
{
  ll x, y;
  Point() {}
  Point(ll x, ll y): x(x), y(y) {}

  bool operator<(const Point &o) const {
    return x<o.x || (x==o.x && y<o.y);
  }
  Point operator+(const Point &o) const {
    return Point(x+o.x, y+o.y);
  }
  Point operator-(const Point &o) const {
    return Point(x-o.x, y-o.y);
  }
};

ll dist(const Point &a, const Point &b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int CCW(const Point &a, const Point &b, const Point &c) 
{
  ll t=(b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
  return t?t>0?1:-1:0;
}

std::vector<Point> convexHull(std::vector<Point> points)
{
  std::sort(points.begin(), points.end());

  std::vector<Point> lower, upper;
  for (const Point &p:points) {
    while (lower.size()>1 && CCW(lower[lower.size()-2], lower.back(), p)<=0) {
      lower.pop_back();
    }
    lower.push_back(p);
  }
  for (auto p=points.rbegin();p!=points.rend();++p) {
    while (upper.size()>1 && CCW(upper[upper.size()-2], upper.back(), *p)<=0) {
      upper.pop_back();
    }
    upper.push_back(*p);
  }

  lower.pop_back(), upper.pop_back();
  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

ll rotCali(const std::vector<Point> &hull)
{
  int n=hull.size();
  if (n<2) return 0;
  if (n==2) return dist(hull[0], hull[1]);

  ll max=0LL;
  int i=0,j=1;
  for (;i<n;++i) {
    // std::cout << i << '\t' << hull[i].x << ' ' << hull[i].y << '\n';
    int ni=(i+1)%n;
    while (1) {
      int nj=(j+1)%n;

      if (CCW(hull[i], hull[ni], hull[nj]-hull[j]+hull[ni])>0) j=nj;
      else break;
    }
    // std::cout << i << ' ' << j << '\n';
    max=std::max(max, dist(hull[i], hull[j]));
  }
  return max;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<Point> points(n);
  for (Point &p:points)  read(p.x), read(p.y);

  std::vector<Point> hull=convexHull(points);
  std::cout << rotCali(hull);
  
  return 0;
}
// 4225

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

struct Point
{
  long long int x, y;
  Point(){}
  Point(long long int x, long long int y): x(x), y(y) {}

  bool operator<(const Point &o) const {
    return (y==o.y?x<o.x:y<o.y);
  }
};
long long int GCD(long long int a, long long int b)
{
  if (a<b) std::swap(a, b);
  while (b) {
    long long int tmp=a%b;
    a=b;
    b=tmp;
  }
  return a?a:1LL;
}
/* b/a */
struct Frac
{
  long long int a, b;
  Frac(long long int _a, long long int _b) {
    long long int g=GCD(_a, _b);
    a=_a/g;
    b=_b/g;
  }
  bool operator==(const Frac &o) const {
    return (a==o.a) && (b==o.b);
  }
  bool operator<(const Frac &o) const {
    return o.a*b < a*o.b;
  }
};

/* square of distance between two points a and b */
inline long long int dist(const Point &a, const Point &b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

/* square of distance between line ab and point c */
Frac dist(const Point &a, const Point &b, const Point &c)
{
  long long int cross=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
  cross*=cross;
  // return std::sqrt(static_cast<long double>(cross)/static_cast<long double>(dist(a, b)));
  return Frac(dist(a, b), cross);
}

int CCW(const Point &a, const Point &b, const Point &c) 
{
  long long int t=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
  return t?(t>0?1:-1):0;
}

int sqrt_binary(const Frac &f)
{
  long long int l=0, r=1e9, result;
  long long int a=f.a, b=f.b;
  while (l<=r) {
    long long int mid=(l+r)>>1;
    __int128 lhs=static_cast<__int128>(mid)*mid*a;

    if (lhs>=static_cast<__int128>(b)) {
      result=mid;
      r=mid-1;
    } 
    else {
      l=mid+1;
    }
  }
  return result;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, tc=0;
  while (std::cin >> n) {
    if (!n) break;
    std::vector<Point> points(n);
    for (int i=0;i<n;++i) std::cin >> points[i].x >> points[i].y;
    std::sort(points.begin(), points.end());

    Point start=points[0];
    std::sort(points.begin()+1, points.end(), 
      [&start](const Point &a, const Point &b) -> bool {
        int ccw=CCW(start, a, b);
        if (ccw==1) return 1;
        else if (ccw==-1) return 0;
        else return dist(start, a)<dist(start, b);
      });

    std::vector<Point> stk;
    for (const Point &p:points) {
      while (stk.size()>=2 && CCW(stk[stk.size()-2], stk.back(), p)<=0) stk.pop_back();
      stk.push_back(p);
    }

    int s=stk.size();

    Frac min(0, 0);
    for (int i=0;i<s;++i) {
      Point &a=stk[i], &b=stk[(i+1)%s];
      Frac max(0, 0);
      for (int j=0;j<s;++j) if (j!=i && j!=(i+1)%s) {
        if (!max.a && !max.b) max=dist(a, b, stk[j]);
        else max=std::max(max, dist(a, b, stk[j]));
      }
      if (!min.a && !min.b) min=max;
      else min=std::min(min, max);
      min=std::min(min, max);
    }
    min.b*=10000LL;

    int result=sqrt_binary(min);
    std::cout << "Case " << ++tc << ": " << result/100 << '.';
    if (result%100/10==0) std::cout << '0';
    std::cout << result%100 << '\n';
  }

  return 0;
}
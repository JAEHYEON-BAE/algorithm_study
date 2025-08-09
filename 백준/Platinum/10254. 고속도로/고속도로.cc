// 10254

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  #define OUTPUT_BUFFER_SIZE (1<<20)
  
  /* INPUT */
  char get()
  {
    static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
    if (S==T) {
      T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
      if (S==T) return EOF;
    }
    return *S++;
  }
  void read(int &x)
  {
    static char c; x=0;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
    if (MINUS_FLAG) x*=-1;
  }
  void read(long long int &x)
  {
    static char c; x=0;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
    if (MINUS_FLAG) x*=-1;
  }
}

#endif

using ll=long long int;

struct Point
{
  ll x, y;
  Point() {}
  Point(ll x, ll y): x(x), y(y) {}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

inline ll dist(const Point &a, const Point &b) 
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int CCW(const Point &a, const Point &b, const Point &c)
{
  ll x1=b.x-a.x, y1=b.y-a.y;
  ll x2=c.x-a.x, y2=c.y-a.y;
  ll tmp=x1*y2-x2*y1;
  
  if (tmp) {
    if (tmp>0) return 1;
    else return -1;
  }
  else return 0;
}

ll area(const Point &a, const Point &b, const Point &c)
{
  ll x1=b.x-a.x, y1=b.y-a.y;
  ll x2=c.x-a.x, y2=c.y-a.y;
  ll tmp=x1*y2-x2*y1;

  return std::abs(tmp);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int t;  read(t);
  while (t--) {
    int n;  read(n);
    std::vector<Point> points(n);
    for (Point &p:points) read(p.x), read(p.y);

    if (n==2) {
      std::cout << points[0].x << ' ' << points[0].y << ' ' << points[1].x << ' ' << points[1].y << '\n';
      continue;
    }

    /* build convex hull */
    std::sort(points.begin(), points.end(), 
      [] (const Point &a, const Point &b) {
        return a.y==b.y?a.x<b.x:a.y<b.y;
      });

    std::sort(points.begin()+1, points.end(),
      [&points] (const Point &a, const Point &b) {
        ll tmp=CCW(points[0], a, b);
        if (tmp) return tmp>0;
        return dist(points[0], a)<dist(points[0], b);
      });

    std::vector<Point> hull;
    hull.push_back(points[0]), hull.push_back(points[1]);
    for (int i=2;i<n;++i) {
      while (hull.size()>=2 && CCW(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0) hull.pop_back();
      hull.push_back(points[i]);
    }

    /* implement rotating callipers */
    int h=hull.size();
    if (h==2) {
      std::cout << hull[0].x << ' ' << hull[0].y << ' ' << hull[1].x << ' ' << hull[1].y << '\n';
      continue;
    }

    ll max=0LL;
    int bi=-1, bj=-1;

    int i=0, j=1;
    for (;i<h;++i) {
      int ni=(i+1)%h;
      while (1) {
        int nj=(j+1)%h;
        ll curr=area(hull[i], hull[ni], hull[j]);
        ll next=area(hull[i], hull[ni], hull[nj]);

        if (next>curr) j=nj;
        else break;
      }

      ll d1=dist(hull[i], hull[j]);
      if (d1>max) {
        max=d1;
        bi=i;
        bj=j;
      }
      
      ll d2=dist(hull[ni], hull[j]);
      if (d2>max) {
        max=d2;
        bi=ni;
        bj=j;
      }
    }

    std::cout << hull[bi].x << ' ' << hull[bi].y << ' ' << hull[bj].x << ' ' << hull[bj].y << '\n';
  }

  return 0;
}

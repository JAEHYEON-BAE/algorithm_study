// 34081

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

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

struct Pirate
{
  long long int d;
  long long int c;
  Pirate(long long int d, long long int c): d(d), c(c) {}
  bool operator<(const Pirate &o) const {
    return c==o.c?d<o.d:c<o.c;
  }
};


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int n; long long int l;  read(n), read(l);
  long long int x, y, c;

  std::vector<std::pair<long long int, long long int>> pirates(n);
  for (int i=0;i<n;++i) {
    read(x), read(y), read(c);
    long long int dsqr=x*x+y*y;
    long long int d=std::sqrt(dsqr)-1;
    while (d*d<dsqr) ++d;
    if (d<=l) pirates[i]={l-d, c};
  }
  std::sort(pirates.begin(), pirates.end());
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  long long int res=0LL, tmp=0LL;
  for (const auto &[d, c]:pirates) {
    pq.push(c);
    tmp+=c;
    while (pq.size()>d+1) {
      tmp-=pq.top();
      pq.pop();
    }
    res=std::max(res, tmp);
  }
  std::cout << res;
  return 0;
}
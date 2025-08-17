// 16981

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

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
}

#endif

struct Picture
{
  int size, value;
  Picture() {}
  Picture(int s, int v): size(s), value(v) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  
  int n, m;  read(n), read(m);
  
  std::vector<Picture> pictures(n);
  for (Picture &p:pictures) read(p.size), read(p.value);
  
  std::vector<int> frames(m);
  for (int &f:frames) read(f);

  std::sort(pictures.begin(), pictures.end(), 
    [](const Picture &a, const Picture &b) {
      return a.value==b.value?a.size>b.size:a.value>b.value;
    });
  std::sort(frames.begin(), frames.end(), std::greater<>());


  int f=0;
  std::vector<Picture> v;
  for (int p=0;p<n;++p) {
    if (v.empty()) {
      if (pictures[p].size>frames[f]) continue;
      else v.push_back(pictures[p]), ++f;
    }
    else {
      auto pos=std::upper_bound(v.begin(), v.end(), pictures[p],
        [](const Picture &a, const Picture &b) {
          return a.value>b.value;
        });

      if (pos==v.end()) {
        if (pictures[p].size>frames[f]) v.back()=pictures[p];
        else v.push_back(pictures[p]), ++f;
      }
      else *pos=pictures[p];
    }
    if (f>=m) break;
  }
  std::cout << v.size();
  return 0;
}


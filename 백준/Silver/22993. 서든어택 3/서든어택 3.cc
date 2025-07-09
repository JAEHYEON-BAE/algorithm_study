// 22993

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  
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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n;  read(n);
  
  long long int tmp;  read(tmp);
  std::vector<long long int> v(n-1);
  for (int i=0;i<n-1;++i) read(v[i]);
  std::sort(v.begin(), v.end());
  for (const auto &x:v) {
    if (x>=tmp) {
      std::cout << "No";
      return 0;
    }
    tmp+=x;
  }
  std::cout << "Yes";
  return 0;
}
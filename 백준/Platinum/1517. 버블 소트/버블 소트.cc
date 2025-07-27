// 1517

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

class _1517
{
  int n;
  std::vector<int> &v;
  long long int inversion_cnt=0;

  void merge_sort(int l, int r) {
    if (l>=r) return;

    int mid=(l+r)>>1;
    merge_sort(l, mid); merge_sort(mid+1, r);

    std::vector<int> tmp;
    tmp.reserve(r-l+1);
    
    int left_i=l, right_i=mid+1;
    while (left_i<=mid || right_i<=r) {
      if (left_i>mid) tmp.push_back(v[right_i++]);
      else if (right_i>r || v[left_i]<=v[right_i]) tmp.push_back(v[left_i++]);
      else {
        tmp.push_back(v[right_i++]);
        inversion_cnt+=mid-left_i+1;
      }
    }
    assert(tmp.size()==r-l+1);
    for (int i=l;i<=r;++i) {
      v[i]=tmp[i-l];
    }
    return;
  }

public:
  _1517(int n, std::vector<int>& v): n(n), v(v) {}

  long long int result() {
    merge_sort(0, n-1);
    return inversion_cnt;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  
  int n; read(n);
  std::vector<int> v(n);
  for (int i=0;i<n;++i) read(v[i]);

  _1517 x(n, v);
  std::cout << x.result();

 
  return 0;
}
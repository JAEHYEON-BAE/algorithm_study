// 1517

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

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

class Fenwick
{
  int n;
  std::vector<long long int> tree;

public:
  Fenwick(int n): n(n) {
    tree.assign(n+1, 0);
  }
  void insert(int x) {
    for (int i=x;i<=n;i+=i&-i) ++tree[i];
  }
  long long int query(int x) {
    long long int sum=0LL;
    for (int i=x;i>0;i-=i&-i) sum+=tree[i];
    return sum;
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

  /* a: compressed vector */
  std::vector<int> a=v;
  std::sort(v.begin(), v.end());
  
  std::unordered_map<int, int> map;
  for (int i=0;i<n;++i) {
    if (map.find(v[i])==map.end()) map[v[i]]=i+1;
  }

  std::unordered_map<int, int> multiple;
  for (int &i:a) {
    if (++multiple[i]>1) i=map[i]+multiple[i]-1;
    else i=map[i];
  } 

  Fenwick f(n);
  
  long long int cnt=0LL;
  for (int i=n-1;i>=0;--i) {
    cnt+=f.query(a[i]-1);
    f.insert(a[i]);
  }
  std::cout << cnt;
 
  return 0;
}
// 7578

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

class FenwickTree 
{
  int n;
  std::vector<long long int> tree;

  long long int find(int idx) const {
    long long int result=0;
    while (idx>0) {
      result+=tree[idx];
      idx-=(idx&-idx);
    }
    return result;
  }

public:
  FenwickTree(const int &n): n(n) {
    tree.assign(n+1, 0LL);
  }

  void insert(int idx) {
    while (idx<=n) {
      ++tree[idx];
      idx+=(idx&-idx);
    }
  }

  long long int query(int x) const {
    return find(n)-find(x);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;

  int n;  read(n);

  std::unordered_map<int, int> map;
  for (int i=0;i<n;++i) {
    int x;  read(x);
    map[x]=i+1;
  }

  FenwickTree ft(n);

  long long int cnt=0;
  for (int i=0;i<n;++i) {
    int x;  read(x);
    x=map.at(x);
    cnt+=ft.query(x);
    ft.insert(x);
  }
  std::cout << cnt;
  
  return 0;
}
// 1854

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>
#include <cmath>
#include <type_traits>

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
  
  /* OUTPUT */
  char obuf[OUTPUT_BUFFER_SIZE];
  int opos=0;
  inline void flush() 
  {
    fwrite(obuf, 1, opos, stdout);
    opos=0;
  }
  inline void put(char c)
  {
    if (opos==OUTPUT_BUFFER_SIZE) flush();
    obuf[opos++]=c;
  }
  void write(int x)
  {
    if (x==0) return put('0');
    char tmp[11]; int len=0;
    if (x<0) {put('-');x*=-1;}
    while (x) {tmp[len++]='0'+(x%10); x/=10;}
    while (len--) put(tmp[len]);
  }
  inline void write(const char &c) 
  {
    put(c);
  }
  struct FASTIO_FLUSHER
  {
    ~FASTIO_FLUSHER() {flush();}
  } fastio_flusher;
}

#endif

class SegTree
{
  int n;
  int size=1;
  std::vector<int> tree;
  std::vector<int> lazy;

  void init(int node, int s, int e, const std::vector<int> &v) {
    if (s==e) tree[node]=v[s];
    else {
      int mid=(s+e)>>1;
      init(node<<1, s, mid, v);
      init(1|node<<1, mid+1, e, v);
      tree[node]=tree[node<<1]^tree[1|node<<1];
    }
  }

  void update_lazy(int node, int s, int e) {
    if (lazy[node]) {
      if ((e-s+1)&1) tree[node]^=lazy[node];
      if (s!=e) {
        lazy[node<<1]^=lazy[node];
        lazy[1|node<<1]^=lazy[node];
      }
      lazy[node]=0;
    }
  }
  void update_range(int node, int s, int e, int l, int r, int k) {
    update_lazy(node, s, e);
    if (e<l || r<s) return;
    if (l<=s && e<=r) {
      if ((e-s+1)&1) tree[node]^=k;
      if (s!=e) {
        lazy[node<<1]^=k;
        lazy[1|node<<1]^=k;
      }
      return;
    }
    int mid=(s+e)>>1;
    update_range(node<<1, s, mid, l, r, k);
    update_range(1|node<<1, mid+1, e, l, r, k);
    tree[node]=tree[node<<1]^tree[1|node<<1];
  }
  int query_range(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    if (e<l || r<s) return 0;
    if (l<=s && e<=r) return tree[node];
    int mid=(s+e)>>1;
    return query_range(node<<1, s, mid, l, r)^query_range(1|node<<1, mid+1, e, l, r);
  }

public:
  SegTree(int n, const std::vector<int> &v): n(n) {
    while (size<n+1) size<<=1;
    size<<=1;
    tree.assign(size, 0);
    lazy.assign(size, 0);
    init(1, 0, n-1, v);
  }
  void update_range(int l, int r, int k) {
    return update_range(1, 0, n-1, l, r, k);
  } 
  int query_range(int l, int r) {
    return query_range(1, 0, n-1, l, r);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n, m;  read(n);
  std::vector<int> v(n);
  for (int i=0;i<n;++i) read(v[i]);
  SegTree st(n, v);

  read(m);
  int q, i, j, k;
  while (m--) {
    read(q);
    if (q==1) {
      read(i), read(j), read(k);
      st.update_range(i, j, k);
    }
    else if (q==2) {
      read(i), read(j);
      write(st.query_range(i, j));
      write('\n');
    }
  }

  
  return 0;
}
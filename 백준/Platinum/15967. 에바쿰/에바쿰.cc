// 15967

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

/* INPUT */
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
void read(int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(ll &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}


class SegTree
{
  int N;
  int size;
  std::vector<ll> tree, lazy;

  void _init(const std::vector<ll> &a, int node, int s, int e) {
    if (s==e) tree[node]=a[s];
    else {
      int mid=(s+e)>>1;
      _init(a, node<<1, s, mid);
      _init(a, 1|node<<1, mid+1, e);
      tree[node]=tree[node<<1]+tree[1|node<<1];
    }
  }
  void _update(int idx, int node, int s, int e, ll d) {
    if (idx<s || idx>e) return;
    tree[node]+=d;
    if (s==e) return;
    int mid=(s+e)>>1;
    if (idx<=mid) _update(idx, node<<1, s, mid, d);
    else _update(idx, 1|node<<1, mid+1, e, d);
  }
  void _propagate(int node, int s, int e) {
    // std::cerr << "PROPAGATE: " << s << '\t' << e << std::endl;
    if (lazy[node]) {
      tree[node]+=lazy[node]*(e-s+1LL);
      if (s!=e) {
        lazy[node<<1]+=lazy[node];
        lazy[1|node<<1]+=lazy[node];
      }
      lazy[node]=0;
    }
  }
  void _update(int l, int r, int node, int s, int e, ll d) {
    _propagate(node, s, e);
    if (r<s || e<l) return;
    if (l<=s && e<=r) {
      tree[node]+=d*(e-s+1LL);
      if (s!=e) {
        lazy[node<<1]+=d;
        lazy[1|node<<1]+=d;
      }
      return;
    }
    int mid=(s+e)>>1;
    _update(l, r, node<<1, s, mid, d);
    _update(l, r, 1|node<<1, mid+1, e, d);
    tree[node]=tree[node<<1]+tree[1|node<<1];
  }
  ll _query(int l, int r, int node, int s, int e) {
    // std::cerr << "QUERY: " << l << '\t' << r << std::endl;
    _propagate(node, s, e);
    if (r<s || e<l) return 0LL;
    if (l<=s && e<=r) return tree[node];
    int mid=(s+e)>>1;
    return _query(l, r, node<<1, s, mid)+_query(l, r, 1|node<<1, mid+1, e);
  }

public:
  SegTree(int N): N(N) {
    size=1;
    while (size<=N) size<<=1;
    size<<=1;
    tree.assign(size, 0);
    lazy.assign(size, 0);
  }

  void init(const std::vector<ll> &a) {
    _init(a, 1, 0, N-1);
  }

  void update(int idx, ll d) {
    _update(idx, 1, 0, N-1, d);
  }
  void update(int l, int r, ll d) {
    if (r<l+1000) for (int i=l;i<=r;++i) _update(i, 1, 0, N-1, d);
    else _update(l, r, 1, 0, N-1, d);
  }
  ll query(int l, int r) {
    return _query(l, r, 1, 0, N-1);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int N, q1, q2;  read(N), read(q1), read(q2);
  std::vector<ll> a(N);
  for (ll &x:a) read(x);

  SegTree st(N);
  st.init(a);

  int q, n, m, s, e, l;
  for (int i=0;i<q1+q2;++i) {
    read(q);
    if (q==1) {
      read(n), read(m);
      --n;--m;
      std::cout<< st.query(n, m) << '\n';
    }
    else {
      read(s), read(e), read(l);
      --s;--e;
      st.update(s, e, l);
    }
  }

  return 0;
}
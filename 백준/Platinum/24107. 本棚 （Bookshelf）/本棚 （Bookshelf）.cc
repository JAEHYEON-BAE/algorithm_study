// 29682

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

struct Fenwick
{
  int n;
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int idx, ll v) {
    while (idx<=n) {
      tree[idx]=std::max(tree[idx], v);
      idx+=idx&-idx;
    }
  }
  ll query(int idx) const {
    ll res=0;
    while (idx>0) {
      res=std::max(res, tree[idx]);
      idx-=idx&-idx;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<ll> w(n+1);
  ll tot=0;
  for (int i=1;i<=n;++i) {
    read(w[i]); tot+=w[i];
  }
  std::vector<int> a(n);
  for (int &x:a) read(x);

  Fenwick fw(n);

  // maximum weight increasing subsequence
  // dp[i]=w[a[i]]+max{dp[j] s.t. j<i && a[j]<a[i]};
  ll max=0;
  for (int i=0;i<n;++i) {
    ll curr=w[a[i]]+(a[i]>1?fw.query(a[i]-1):0);
    fw.update(a[i], curr);
    max=std::max(max, curr);
  }

  std::cout << (tot-max)*2;
  return 0;
}
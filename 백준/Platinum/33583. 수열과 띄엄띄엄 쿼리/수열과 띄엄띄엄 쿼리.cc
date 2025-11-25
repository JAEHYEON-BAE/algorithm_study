// 33583

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
template <typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

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
template <typename T>
void write(T x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

struct Fenwick
{
  int n;
  std::vector<ll> tree;

  Fenwick(int _n): n(_n), tree(_n, 0) {}

  void update(int i, ll x) {
    for (;i<n;i+=i&-i) tree[i]+=x;
  }
  ll sum(int i) const {
    ll res=0LL;
    for (;i>0;i-=i&-i) res+=tree[i];
    return res;
  }
};
struct Chain
{
  int n;
  Fenwick tr1, tr2;

  Chain(int _n): tr1(_n), tr2(_n) {}

  void update(int i, ll x) {
    tr1.update(i, x);
    tr2.update(i, x*i);
  }
  void update(int l, int r, ll x) {
    tr1.update(l, x);
    if (r+1<n) tr1.update(r+1, -x);

    tr2.update(l, x*l);
    if (r+1<n) tr2.update(r+1, -x*(r+1));
  }
  ll sum(int k) const {
    if (k==0) return 0LL;
    return tr1.sum(k)*(1LL+k)-tr2.sum(k);
  }

  ll sum(int l, int r) const {
    return sum(r)-sum(l-1);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q;  read(n), read(q);

  /** Differential Array D of A
    *   A[i] = sum(j=1..i) D[j]
    *   S[k] = sum(i=1..k) A[i]
    *        = sum(i=1..k) sum(j=1..i) D[j]
    *
    *        = sum(j=1..k) (k+1-j)*D[j]
    * 
    * Therefore, use two Fenwick Tree: of D[j] and j*D[j]
    */
  std::vector<Chain> chains(60, Chain(n/60+2));

  for (int i=1;i<=n;++i) {
    ll x;  read(x);
    chains[i%60].update(1+i/60, 1+i/60, x);
  }

  while (q--) {
    int cmd, l, r, d;  read(cmd), read(l), read(r), read(d);
    if (cmd==1) {
      ll x;  read(x);
      for (int i=0;i<60 && r-l>=i;i+=d) 
        chains[(l+i)%60].update(1+(l+i)/60, 1+(l+i)/60+(r-l-i)/60, x);
    }
    else {
      ll res=0LL;
      for (int i=0;i<60 && r-l>=i;i+=d)
        res+=chains[(l+i)%60].sum(1+(l+i)/60, 1+(l+i)/60+(r-l-i)/60);
      write(res), put('\n');
    }
  }

  flush();
  return 0;
}
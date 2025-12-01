// 17353

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
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

struct Fenwick
{
  // 1 ~ n
  int n;  
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int i, ll x) {
    for (;i<=n;i+=i&-i) tree[i]+=x;
  }

  ll query(int i) const {
    ll res=0ll;
    for (;i>0;i-=i&-i) res+=tree[i];
    return res;
  }
};

struct RURQ
{
  int n;
  Fenwick f1, f2;

  RURQ(int n): n(n), f1(n), f2(n) {}

  void update(int l, int r, ll x) {
    f1.update(l, x);
    f2.update(l, x*l);

    if (r+1<=n) {
      f1.update(r+1, -x);
      f2.update(r+1, -x*(r+1));
    }
  }

  ll query(int i) const {
    return (i+1LL)*f1.query(i)-f2.query(i);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<ll> a(n);
  RURQ rurq(n);
  for (ll &x:a) read(x);

  // DIFFERENTIAL ARRAY !

  int q;  read(q);
  while (q--) {
    int cmd;  read(cmd);
    if (cmd==1) {
      int l, r;  read(l), read(r);
      rurq.update(l, r, 1);
      if (r+1<=n) {
        rurq.update(r+1, r+1, -1LL*(r+1-l));
      }
    }
    else {
      int x;  read(x);
      write(rurq.query(x)+a[x-1]);
      put('\n');
    }
  }
  flush();
  return 0;
}
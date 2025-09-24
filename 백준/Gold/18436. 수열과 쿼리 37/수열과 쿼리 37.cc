// 18436

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

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
void write(int x)
{
  if (x==0) return put('0');
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}
struct FASTIO_FLUSHER
{
  ~FASTIO_FLUSHER() {flush();}
} fastio_flusher;

class Fenwick
{
  int n;
  std::vector<int> tree;
  std::vector<int> v;

  int sum(int i) const {
    int res=0;
    while (i>0) {
      res+=tree[i];
      i-=i&-i;
    }
    return res;
  }

public:
  Fenwick(int n, const std::vector<int> &a): n(n) {
    tree.assign(n+1, 0);
    v.resize(n+1);
    for (int i=1;i<=n;++i) {
      v[i]=a[i-1]&1;
      tree[i]+=v[i];
    }
    for (int i=1;i<=n;++i) {
      int j=i+(i&-i);
      if (j<=n) tree[j]+=tree[i];
    }
  }
  void update(int i, int x) {
    if (v[i]==(x&1)) return;
    int d=(x&1)?1:-1;
    v[i]+=d;
    while (i<=n) {
      tree[i]+=d;
      i+=i&-i;
    }
  }
  int query(int l, int r) {
    return sum(r)-sum(l-1);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<int> a(n);
  for (int &x:a) read(x);

  Fenwick fw(n, a);
  
  int m;  read(m);
  for (int i=0;i<m;++i) {
    int q;  read(q);
    if (q==1) {
      int i, x;  read(i), read(x);
      fw.update(i, x);
    }
    else {
      int l, r;  read(l), read(r);
      if (q==2) write(r-l+1 - fw.query(l, r));
      else write(fw.query(l, r));

      put('\n');
    }
  }
  return 0;
}
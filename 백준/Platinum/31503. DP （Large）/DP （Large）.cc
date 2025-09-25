// 31501

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_map>

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

struct Fenwick
{
  int n;
  std::vector<int> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int i, int x) {
    while (i<=n) {
      tree[i]=std::max(tree[i], x);
      i+=i&-i;
    }
  }
  int query(int i) const {
    int res=0;
    while (i>0) {
      res=std::max(res, tree[i]);
      i-=i&-i;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q;  read(n), read(q);
  std::vector<int> d(n);
  std::set<int> set;
  for (int &x:d) {
    read(x);
    set.insert(x);
  }

  std::unordered_map<int, int> rank;
  int id=1;
  for (const int &x:set) rank[x]=id++;

  // coordinate compression
  for (int &x:d) x=rank[x];

  int m=rank.size();

  std::vector<int> l(n, 0), r(n, 0);
  Fenwick lf(m), rf(m);
  for (int i=0;i<n;++i) {
    l[i]=1+(d[i]>1?lf.query(d[i]-1):0);
    lf.update(d[i], l[i]);
  }
  for (int i=n-1;i>=0;--i) {
    int tmp=m+1-d[i];
    r[i]=1+(tmp>1?rf.query(tmp-1):0);
    rf.update(tmp, r[i]);
  }
  
  while (q--) {
    int a;  read(a);  --a;
    write(l[a]+r[a]-1);
    put('\n');
  }
  
  return 0;
}
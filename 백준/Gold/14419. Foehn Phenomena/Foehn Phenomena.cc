// 14419

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
void write(ll x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q; ll s, t;  read(n), read(q), read(s), read(t);
  std::vector<ll> a(n+1), d(n+1);
  for (int i=0;i<=n;++i) read(a[i]);
  ll res=0LL;
  for (int i=1;i<=n;++i) {
    d[i]=a[i]-a[i-1];
    if (d[i]>0) res-=s*d[i];
    else res-=t*d[i];
  }

  for (int i=0;i<q;++i) {
    int l, r; ll x;  read(l), read(r), read(x);
    if (d[l]>0) {
      if (d[l]+x>0) res-=s*x;
      else res=res+s*d[l]-t*(d[l]+x);
    }
    else {
      if (d[l]+x>0) res=res+t*d[l]-s*(d[l]+x);
      else res-=t*x;
    }
    d[l]+=x;

    if (r+1<=n) {
      if (d[r+1]>0) {
        if (d[r+1]-x>0) res-=s*(-x);
        else res=res+s*d[r+1]-t*(d[r+1]-x);
      }
      else {
        if (d[r+1]-x>0) res=res+t*d[r+1]-s*(d[r+1]-x);
        else res+=t*x;
      }
      d[r+1]-=x;
    }
    
    write(res);
    put('\n');
  }
  flush();
  return 0;
}

// 33917

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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<int> a(n);
  for (int &x:a) read(x);
  std::vector<ll> b(n);
  ll s0=0, s1=0;
  for (int i=0;i<n;++i) {
    read(b[i]);
    if (a[i]) s1+=b[i];
    else s0+=b[i];
  }

  int cnt=0;
  ll d0=0, d1=0;
  for (int i=n-1;i>0;--i) {
    if (a[i]) d1+=b[i];
    else d0+=b[i];

    if (d1>d0) {
      s0+=d0;
      s1+=d1;
      ++cnt;
    }
  }

  std::cout << cnt+1 << ' ' << s1-s0;
  return 0;
}
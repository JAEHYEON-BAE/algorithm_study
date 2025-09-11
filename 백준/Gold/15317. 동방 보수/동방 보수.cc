// 15317

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
void read(long long int &x)
{
  static char c; x=0;
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

  int n, m, x;  read(n), read(m), read(x);
  std::vector<long long int> c(n), s(m);
  for (long long int &x:c) read(x);
  for (long long int &x:s) read(x);

  std::sort(c.begin(), c.end());
  std::sort(s.begin(), s.end());

  auto valid=[&](const int &k) -> bool {
    if (k==0) return true;

    long long int need=0;
    for (int i=0;i<k;++i) {
      if (c[i]>s[m-k+i]) {
        need+=(c[i]-s[m-k+i]);
        if (need>x) return false;
      }
    }
    return need<=x;
  };

  int l=0, r=std::min(n, m);
  int ans=0;
  while (l<=r) {
    int mid=(l+r)>>1;
    if (valid(mid)) ans=mid, l=mid+1;
    else r=mid-1;
  }
  std::cout << ans;
  return 0;
}
// 16877 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<int> f(33);
  f[0]=f[1]=1;
  for (int i=2;i<33;++i) f[i]=f[i-1]+f[i-2];
  
  int n;  read(n);
  std::vector<int> p(n);

  int maxp=3'000'000;

  std::vector<int> grundy(maxp, 0);
  std::vector<bool> seen(20);
  for (int i=1;i<=maxp;++i) {
    std::fill(seen.begin(), seen.end(), 0);
    for (int k:f) {
      if (i-k>=0) seen[grundy[i-k]]=1;
      else break;
    }

    int mex=0;
    while (seen[mex]) ++mex;
    grundy[i]=mex;
  }

  int res=0;
  for (int &x:p) {
    read(x);
    res^=grundy[x];
  }
  std::cout << (res?"koosaga":"cubelover");

  return 0;
}

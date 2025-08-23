// 19805

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

#define INPUT_BUFFER_SIZE (1<<20)

/* INPUT */
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

  int n; read(n);
  int tot=0, x, min=1001;
  for (int i=0;i<n;++i) {
    read(x);
    x=x&1?x:x-1;
    tot+=x;
    min=std::min(min, x);
  }
  if (!(tot&1)) tot-=min;
  std::cout << tot;
  
  return 0;
}


// 15100

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
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string a, b;  read(a), read(b);
  assert(a.size()==b.size());
  int n=a.size();
  int l, r;
  for (int i=0;i<n;++i) if (a[i]!=b[i]) {
    l=i; break;
  }
  for (int i=n-1;i>=0;--i) if (a[i]!=b[i]) {
    r=i; break;
  }

  std::reverse(a.begin()+l, a.begin()+r+1);
  if (a!=b) {std::cout << '0'; return 0;}
  int cnt=1;
  for (int d=1;l-d>=0 && r+d<n;++d) {
    if (a[l-d]==b[r+d] && a[r+d]==b[l-d]) ++cnt;
    else break;
  }
  std::cout << cnt;
  return 0;
}
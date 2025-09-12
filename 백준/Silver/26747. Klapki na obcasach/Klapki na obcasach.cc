// 26747

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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<int> h(n);
  for (int &x:h) read(x);

  int m;  read(m);
  std::vector<int> a(m);
  for (int &x:a) read(x);

  int t;  read(t);
  
  std::sort(h.begin(), h.end(), std::greater<int>());
  std::sort(a.begin(), a.end());

  int i=0, j=0;
  int cnt=0;
  for (;i<n;++i) {
    if (h[i]>=t) ++cnt;
    else {
      while (j<m && h[i]+a[j]<t) ++j;
      if (j==m) break;
      else ++j, ++cnt;
    }
  }
  std::cout << cnt;
  
  return 0;
}
// 13711

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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; read(n);
  int x;
  std::vector<int> inv_a(n), s(n);
  for (int i=0;i<n;++i) {
    read(x); --x;
    inv_a[x]=i;
  }
  for (int i=0;i<n;++i) {
    read(x); --x;
    s[i]=inv_a[x];
  }

  std::vector<int> lis;
  lis.reserve(n);
  for (const int &i:s) {
    auto iter=std::lower_bound(lis.begin(), lis.end(), i);
    if (iter==lis.end()) lis.push_back(i);
    else *iter=i;
  }

  std::cout << lis.size();
  return 0;
}